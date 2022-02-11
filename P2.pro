QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchart.cpp \
    chart.cpp \
    chartview.cpp \
    dataset.cpp \
    exception.cpp \
    headeritem.cpp \
    item.cpp \
    linechart.cpp \
    main.cpp \
    mainview.cpp \
    model.cpp \
    piechart.cpp \
    tableview.cpp

HEADERS += \
    barchart.h \
    chart.h \
    chartview.h \
    dataset.h \
    exception.h \
    headeritem.h \
    item.h \
    linechart.h \
    mainview.h \
    model.h \
    piechart.h \
    tableview.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resource.qrc
