QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Boss.cpp \
    Bullet.cpp \
    Cherry.cpp \
    Game.cpp \
    GhostBullet.cpp \
    Health.cpp \
    Pacman.cpp \
    RedGhost.cpp \
    Score.cpp \
    ShooterGhost.cpp \
    main.cpp

HEADERS += \
    Boss.h \
    Bullet.h \
    Cherry.h \
    Game.h \
    GhostBullet.h \
    Health.h \
    Pacman.h \
    RedGhost.h \
    Score.h \
    ShooterGhost.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \

DISTFILES += \
