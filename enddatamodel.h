#ifndef ENDDATAMODEL_H
#define ENDDATAMODEL_H

#include "nodes/NodeDataModel.hpp"
#include "ExecutionData.h"

class EndDataModel : public QtNodes::NodeDataModel
{
    Q_OBJECT
public:
    EndDataModel();

    QString caption() const override
    { return QStringLiteral("End Wave"); }

    bool captionVisible() const override
    { return true; }

    QString name() const override
    { return QStringLiteral("WaveEnd"); }

    QWidget *embeddedWidget() override { return nullptr; }

public:

    unsigned int
    nPorts(QtNodes::PortType portType) const override;

    QtNodes::NodeDataType
    dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

    std::shared_ptr<QtNodes::NodeData>
    outData(QtNodes::PortIndex port) override
    {
        return std::static_pointer_cast<QtNodes::NodeData>(_execution);
    }

    void
    setInData(std::shared_ptr<QtNodes::NodeData>, int) override
    { }

    ConnectionPolicy
    portInConnectionPolicy(QtNodes::PortIndex) const override
    {
      return ConnectionPolicy::Many;
    }


private:

  std::shared_ptr<ExecutionData> _execution;
};

#endif // ENDDATAMODEL_H
