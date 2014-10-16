#include "dbmanager.h"

#include <QCoreApplication>

#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

#define PRINT_STATE(ok) { qDebug() << (ok ? "...Done" : "...Failed"); }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DbManager dbManager;
    QSqlDatabase db = dbManager.sqlDatabase();

    //=====================================================
    qDebug() << "Test insert";
    QSqlQuery sqlQuery(db);
    bool ok = sqlQuery.exec("INSERT INTO profile(profile_name, email) "
                            "VALUES('test_profile', 'example@mail.com')");
    PRINT_STATE(ok);
    if (!ok)
    {
        qCritical() << "Cannot execute INSERT query " << sqlQuery.lastError().text();
        return 0;
    }

    //=====================================================
    qDebug() << "Test select";
    ok = sqlQuery.exec("SELECT profile_name, email FROM profile");
    PRINT_STATE(ok);
    if (!ok)
    {
        qCritical() << "Cannot execute SELECT query " << sqlQuery.lastError().text();
        return 0;
    }
    while (sqlQuery.next())
    {
        qDebug() << "profile_name: " << sqlQuery.value(0).toString();
        qDebug() << "email: " << sqlQuery.value(1).toString();
    }

    //=====================================================
    qDebug() << "Test delete";
    ok = sqlQuery.exec("DELETE FROM profile WHERE profile_name = 'test_profile'");
    PRINT_STATE(ok);
    if (!ok)
    {
        qCritical() << "Cannot execute DELETE query " << sqlQuery.lastError().text();
        return 0;
    }

    return 1;
}
