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
    Timer.cpp \
    Word.cpp \
    custom.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    newgame.cpp \
    rank.cpp \
    whichgame.cpp

HEADERS += \
    ../NCYU_Class/EnglishTypingGame/Article.h \
    ../NCYU_Class/EnglishTypingGame/Player.h \
    ../NCYU_Class/EnglishTypingGame/Question.h \
    ../NCYU_Class/EnglishTypingGame/Word.h \
    Article.h \
    Player.h \
    Question.h \
    RecordrRank.h \
    Timer.h \
    Word.h \
    custom.h \
    form.h \
    mainwindow.h \
    menu.h \
    newgame.h \
    rank.h \
    whichgame.h

FORMS += \
    RecordRank.ui \
    custom.ui \
    form.ui \
    mainwindow.ui \
    menu.ui \
    newgame.ui \
    rank.ui \
    whichgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Toeic.txt \
    temp.txt \
    vocabulary.txt

RESOURCES += \
    resource.qrc

RC_ICONS = EnglishDict_icon.ico
