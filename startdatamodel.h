#ifndef STARTDATAMODEL_H
#define STARTDATAMODEL_H

#include "nodes/NodeDataModel.hpp"

class StartDataModel : public NodeDataModel
{
    Q_OBJECT
public:
    StartDataModel();
    QString
    caption() const override
    { return QStringLiteral("Start Wave"); }

    bool
    captionVisible() const override
    { return true; }

    QString
    name() const override
    { return QStringLiteral("WaveStart"); }
public:

    QJsonObject
    save() const override;

    void
    restore(QJsonObject const &p) override;
public:

    unsigned int
    nPorts(PortType portType) const override;

    NodeDataType
    dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData>
    outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData>, int) override
    { }

    QWidget *
    embeddedWidget() override { return _lineEdit; }

private Q_SLOTS:

  void
  onTextEdited(QString const &string);

private:
};

#endif // STARTDATAMODEL_H
