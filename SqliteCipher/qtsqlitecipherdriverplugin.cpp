#include <qsqldriverplugin.h>
#include <qstringlist.h>                                                                                                                           
#include "qsql_sqlite_p.h"

QT_BEGIN_NAMESPACE

static const char * const kDriverName = "QtSQLiteCipher";

class QtSqliteCipherDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "qtsqlitecipher.json")

public:
    QtSqliteCipherDriverPlugin();
 
    QSqlDriver* create(const QString &name);
};

QtSqliteCipherDriverPlugin::QtSqliteCipherDriverPlugin()
    : QSqlDriverPlugin()
{
}

QSqlDriver* QtSqliteCipherDriverPlugin::create(const QString &name)
{
    if (name == QLatin1String(kDriverName)) 
	{
        QSQLiteDriver* driver = new QSQLiteDriver();
        return driver;
    }
    return 0;
}

QT_END_NAMESPACE

#include "qtsqlitecipherdriverplugin.moc"
