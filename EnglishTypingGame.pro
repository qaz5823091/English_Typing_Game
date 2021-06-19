QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Article.cpp \
    Player.cpp \
    Question.cpp \
    RecordRank.cpp \
    Word.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    ranklist.cpp

HEADERS += \
    Article.h \
    Player.h \
    Question.h \
    RecordrRank.h \
    Word.h \
    mainwindow.h \
    menu.h \
    ranklist.h

FORMS += \
    RecordRank.ui \
    mainwindow.ui \
    menu.ui \
    ranklist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Toeic.txt \
    test4.txt \
    vocabulary.txt

RESOURCES += \
    resource.qrc

RC_ICONS = EnglishDict_icon.ico
