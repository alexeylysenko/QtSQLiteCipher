CONFIG(debug, debug|release): TARGET = qtsqlitecipherd
CONFIG(release, debug|release): TARGET = qtsqlitecipher

TEMPLATE = lib

DEFINES     += QT_PLUGIN

QT      += core sql sql-private core-private

include($$PWD/sqlite/sqlite3.pri)

HEADERS  += $$PWD/qsql_sqlite_p.h

SOURCES  += $$PWD/qsql_sqlite.cpp \
            $$PWD/qtsqlitecipherdriverplugin.cpp

OTHER_FILES += qtsqlitecipher.json

INCLUDEPATH += $$[QT_INSTALL_PREFIX]/../Src/qtbase/src/sql/kernel
