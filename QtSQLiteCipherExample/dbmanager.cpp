#include "dbmanager.h"

#include "dbschema.h"

#include <QSqlQuery>
#include <QSqlError>

#include <QPluginLoader>
#include <QSqlDriverPlugin>

#include <QDebug>

static const char * const kDatabaseFileName = "db.dat";

QString sqliteLibraryPath()
{

#ifdef QT_DEBUG
    QString filePath = "/path/to/qtsqlitecipherd";
#else
    QString filePath = "/path/to/qtsqlitecipher";
#endif

    return filePath;
}

DbManager::DbManager(QObject *parent) :
    QObject(parent)
{
    openDb();
}

DbManager::~DbManager()
{
    QString connectionName = m_db.connectionName();
    m_db.close();
    m_db = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectionName);
}

void DbManager::openDb()
{
    QString filePath = sqliteLibraryPath();
    QPluginLoader loader(filePath);
    QObject *plugin = loader.instance();

    if (!plugin)
    {
        qCritical() << "Loading plugin failed";
        return;
    }

    QSqlDriverPlugin *sqlPlugin  = qobject_cast<QSqlDriverPlugin *>(plugin);

    if (!sqlPlugin )
    {
        qCritical() << "Loading sqlite plugin failed";
        return;
    }

    m_db = QSqlDatabase::addDatabase(sqlPlugin->create("QtSQLiteCipher"));
    m_db.setPassword("1234567890");

    m_db.setConnectOptions("QSQLITE_BUSY_TIMEOUT=20000");
    m_db.setDatabaseName(kDatabaseFileName);
    if (!m_db.open())
    {
        QString errorText(m_db.lastError().text());
        qCritical() << errorText;
        return;
    }

    QSqlQuery sqlQuery(m_db);
    sqlQuery.exec("PRAGMA foreign_keys = ON;");
    if (m_db.tables(QSql::Tables).isEmpty())
        createTables();
}

void DbManager::createTables()
{
    int tablesCount = arraySize(kCreationScriptsList);
    for (int i = 0; i < tablesCount; ++i)
    {
        QSqlQuery sqlQuery(m_db);
        bool result = sqlQuery.exec(kCreationScriptsList[i]);
        Q_ASSERT_X(result,
                   Q_FUNC_INFO,
                   sqlQuery.lastError().text().toLocal8Bit());
    }
}

QSqlDatabase DbManager::sqlDatabase() const
{
    return m_db;
}

