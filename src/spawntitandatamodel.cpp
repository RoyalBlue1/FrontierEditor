#include "spawntitandatamodel.h"
#include <qgridlayout.h>
SpawnTitanDataModel::SpawnTitanDataModel()
{
	QGridLayout(_widget);
}
unsigned int SpawnTitanDataModel::nPorts(QtNodes::PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case QtNodes::PortType::In:
		result = 1;
		break;

	case QtNodes::PortType::Out:
		result = 2;

	default:
		break;
	}

	return result;
}

QtNodes::NodeDataType SpawnTitanDataModel::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
	switch (portType)
	{
	case QtNodes::PortType::In:
		return ExecutionData().type();
	case QtNodes::PortType::Out:
		if (portIndex == 0)
			return EntityData().type();
		else
			return ExecutionData().type();
	}
	return NodeDataType();
}
std::shared_ptr<QtNodes::NodeData> SpawnTitanDataModel::outData(QtNodes::PortIndex portIndex)
{
	if (portIndex == 0)
		return std::static_pointer_cast<QtNodes::NodeData>(_entities);
	else
		return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}
