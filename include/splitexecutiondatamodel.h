#ifndef SPLITEXECUTIONDATAMODEL_H
#define SPLITEXECUTIONDATAMODEL_H

#include <QtWidgets/QLabel>
#include <vector>

#include "nodes/NodeDataModel.hpp"
#include "nodes/Connection.hpp"

#include "ExecutionData.h"
#include "EntityData.h"

class SplitExecutionDataModel : public QtNodes::NodeDataModel
{
	Q_OBJECT
  public:
	SplitExecutionDataModel();
	QString caption() const override
	{
		return QStringLiteral("Split");
	}

	bool captionVisible() const override
	{
		return false;
	}

	QString name() const override
	{
		return QStringLiteral("Split Execution");
	}

	QWidget* embeddedWidget() override
	{
		return nullptr;
	}

  public:
	unsigned int nPorts(QtNodes::PortType portType) const override;

	QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

	std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override;

	ConnectionPolicy portInConnectionPolicy(QtNodes::PortIndex) const override
	{
		return ConnectionPolicy::Many;
	}

	void setInData(std::shared_ptr<QtNodes::NodeData> data, int) override {}

	void setInData(std::shared_ptr<QtNodes::NodeData> data, int, const QUuid& connectionId) override {}

	ConnectionPolicy portOutConnectionPolicy(QtNodes::PortIndex) const
	{
		return ConnectionPolicy::One;
	}

  private:
	std::shared_ptr<ExecutionData> _execution;
	std::vector<std::pair<QUuid, int>> inputExecution;
};

#endif // SPLITEXECUTIONDATAMODEL_H
