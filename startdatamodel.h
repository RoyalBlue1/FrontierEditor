#ifndef STARTDATAMODEL_H
#define STARTDATAMODEL_H

#include "nodes/NodeDataModel.hpp"
#include "ExecutionData.h"

class StartDataModel : public QtNodes::NodeDataModel
{
    Q_OBJECT
public:
    StartDataModel();

    QString caption() const override
    { return QStringLiteral("Start Wave"); }

    bool captionVisible() const override
    { return true; }

    QString name() const override
    { return QStringLiteral("WaveStart"); }

    QWidget *embeddedWidget() override { return nullptr; }

public:

    unsigned int
    nPorts(QtNodes::PortType portType) const override;

    QtNodes::NodeDataType
    dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

    std::shared_ptr<QtNodes::NodeData>
    outData(QtNodes::PortIndex port) override;

    void
    setInData(std::shared_ptr<QtNodes::NodeData>, int) override
    { }



private:

  std::shared_ptr<ExecutionData> _execution;
};

#endif // STARTDATAMODEL_H
