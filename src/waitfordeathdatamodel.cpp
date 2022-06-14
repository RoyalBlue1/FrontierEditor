#include "waitfordeathdatamodel.h"

WaitForDeathDataModel::WaitForDeathDataModel()
{

}

unsigned int
WaitForDeathDataModel::
nPorts(QtNodes::PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case QtNodes::PortType::In:
		result = 2;
		break;

	case QtNodes::PortType::Out:
		result = 1;

	default:
		break;
	}

	return result;
}

QtNodes::NodeDataType
WaitForDeathDataModel::
dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
	switch(portType)
	{
	case QtNodes::PortType::Out:
		return ExecutionData().type();
	case QtNodes::PortType::In:
		if(portIndex == 0)
			return EntityData().type();
		else
			return ExecutionData().type();
	}
	return NodeDataType();
}
std::shared_ptr<QtNodes::NodeData>
WaitForDeathDataModel::outData(QtNodes::PortIndex portIndex)
{

	return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}

void WaitForDeathDataModel::setInData(std::shared_ptr<QtNodes::NodeData> data, int, const QUuid& connectionId)
{

}
