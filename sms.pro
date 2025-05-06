QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allstuinform.cpp \
    awardfind.cpp \
    awardmanage.cpp \
    classfind.cpp \
    classmanage.cpp \
    coursefind.cpp \
    coursemanage.cpp \
    dormanage.cpp \
    dormfind.cpp \
    feefind.cpp \
    feemanage.cpp \
    findscore.cpp \
    insertlogin.cpp \
    main.cpp \
    globle.cpp\
    mainwindow.cpp \
    deletelogin.cpp \
    manager.cpp \
    scoremanage.cpp \
    seeallstuinform.cpp \
    seedorminfor.cpp \
    studentform.cpp \
    stuinformanage.cpp \
    updatelogin.cpp \
    userlogin.cpp\

HEADERS += \
    allstuinform.h \
    awardfind.h \
    awardmanage.h \
    classfind.h \
    classmanage.h \
    coursefind.h \
    coursemanage.h \
    dormanage.h \
    dormfind.h \
    feefind.h \
    feemanage.h \
    findscore.h \
    globle.h \
    mainwindow.h \
    scoremanage.h \
    seeallstuinform.h \
    seedorminfo.h \
    studentform.h \
    stuinformanage.h \
    userlogin.h\
    updatelogin.h\
    manager.h\
    insertlogin.h\
    deletelogin.h\


FORMS += \
    mainwindow.ui\
    deletelogin.ui\
    manager.ui \
    userlogin.ui\
    insertlogin.ui\
    stuinformanage.ui\
    dormanage.ui\
    awardmanage.ui\
    scoremanage.ui\
    coursemanage.ui\
    classmanage.ui\
    feemanage.ui\
    seeallstuinform.ui\
    seedorminfo.ui\
    updatelogin.ui\
    studentform.ui\
    allstuinform.ui\
    findscore.ui\
    dormfind.ui\
    coursefind.ui\
    awardfind.ui\
    classfind.ui\
    feefind.ui\




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
