#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = 0);
    ~DbManager();

    QSqlDatabase sqlDatabase() const;

private:
    void openDb();
    void createTables();

    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
