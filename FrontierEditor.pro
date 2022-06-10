QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network gui opengl

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += NODE_EDITOR_STATIC
SOURCES += \
    enddatamodel.cpp \
    main.cpp \
    mainwindow.cpp \
    mapmarker.cpp \
    minimapgraphicsview.cpp \
    nodes/Connection.cpp \
    nodes/ConnectionBlurEffect.cpp \
    nodes/ConnectionGeometry.cpp \
    nodes/ConnectionGraphicsObject.cpp \
    nodes/ConnectionPainter.cpp \
    nodes/ConnectionState.cpp \
    nodes/ConnectionStyle.cpp \
    nodes/DataModelRegistry.cpp \
    nodes/FlowScene.cpp \
    nodes/FlowView.cpp \
    nodes/FlowViewStyle.cpp \
    nodes/Node.cpp \
    nodes/NodeConnectionInteraction.cpp \
    nodes/NodeDataModel.cpp \
    nodes/NodeGeometry.cpp \
    nodes/NodeGraphicsObject.cpp \
    nodes/NodePainter.cpp \
    nodes/NodeState.cpp \
    nodes/NodeStyle.cpp \
    nodes/Properties.cpp \
    nodes/StyleCollection.cpp \
    positionmodel.cpp \
    spawnarctitandatamodel.cpp \
    spawnnuketitandatamodel.cpp \
    splitexecutiondatamodel.cpp \
    startdatamodel.cpp \
    waitfordeathdatamodel.cpp

HEADERS += \
    EntityData.h \
    ExecutionData.h \
    gamemap.h \
    mainwindow.h \
    mapmarker.h \
    minimapgraphicsview.h \
    enddatamodel.h \
    mainwindow.h \
    nodes/Compiler.hpp \
    nodes/Connection.hpp \
    nodes/ConnectionBlurEffect.hpp \
    nodes/ConnectionGeometry.hpp \
    nodes/ConnectionGraphicsObject.hpp \
    nodes/ConnectionPainter.hpp \
    nodes/ConnectionState.hpp \
    nodes/ConnectionStyle.hpp \
    nodes/DataModelRegistry.hpp \
    nodes/Export.hpp \
    nodes/FlowScene.hpp \
    nodes/FlowView.hpp \
    nodes/FlowViewStyle.hpp \
    nodes/memory.hpp \
    nodes/Node.hpp \
    nodes/NodeConnectionInteraction.hpp \
    nodes/NodeData.hpp \
    nodes/NodeDataModel.hpp \
    nodes/NodeGeometry.hpp \
    nodes/NodeGraphicsObject.hpp \
    nodes/NodePainter.hpp \
    nodes/NodePainterDelegate.hpp \
    nodes/NodeState.hpp \
    nodes/NodeStyle.hpp \
    nodes/OperatingSystem.hpp \
    nodes/PortType.hpp \
    nodes/Properties.hpp \
    nodes/QStringStdHash.hpp \
    nodes/QUuidStdHash.hpp \
    nodes/Serializable.hpp \
    nodes/Style.hpp \
    nodes/StyleCollection.hpp \
    nodes/TypeConverter.hpp \
    positionmodel.h \
    startdatamodel.h \
    util.h \ 
    spawnarctitandatamodel.h \
    spawnnuketitandatamodel.h \
    splitexecutiondatamodel.h \
    startdatamodel.h \
    waitfordeathdatamodel.h



FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc \
    nodes/resources/resources.qrc
