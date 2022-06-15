QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network gui opengl

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += NODE_EDITOR_STATIC
SOURCES += \
    src/spawntitandatamodel.cpp \
    src/enddatamodel.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mapmarker.cpp \
    src/minimapgraphicsview.cpp \
    src/tcphandler.cpp \
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
    src/positionmodel.cpp \
    src/spawnarctitandatamodel.cpp \
    src/spawnnuketitandatamodel.cpp \
    src/splitexecutiondatamodel.cpp \
    src/startdatamodel.cpp \
    src/waitfordeathdatamodel.cpp

HEADERS += \
    include/EntityData.h \
    include/ExecutionData.h \
    include/gamemap.h \
    include/mainwindow.h \
    include/mapmarker.h \
    include/minimapgraphicsview.h \
    include/enddatamodel.h \
    include/mainwindow.h \
    include/spawntitandatamodel.h \
    include/tcphandler.h \
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
    include/positionmodel.h \
    include/startdatamodel.h \
    include/util.h \
    include/spawnarctitandatamodel.h \
    include/spawnnuketitandatamodel.h \
    include/splitexecutiondatamodel.h \
    include/startdatamodel.h \
    include/waitfordeathdatamodel.h



FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc \
    nodes/resources/resources.qrc

INCLUDEPATH += $$PWD/include
