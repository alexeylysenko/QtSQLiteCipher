# see http://sourceforge.net/projects/wxcode

DEFINES += SQLITE_HAS_CODEC

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

HEADERS += \
    $$PWD/sqlite3.h \
    $$PWD/codec.h \
    $$PWD/rijndael.h \
    $$PWD/sha2.h \
    $$PWD/sqlite3ext.h

SOURCES += \
    $$PWD/sqlite3.c \
    $$PWD/sqlite3secure.c \
    $$PWD/codec.c \
    $$PWD/rijndael.c \
    $$PWD/codecext.c \
    $$PWD/extensionfunctions.c \
    $$PWD/sha2.c \
    $$PWD/shell.c
