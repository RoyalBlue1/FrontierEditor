#include "startdatamodel.h"

StartDataModel::StartDataModel()
{

}

unsigned int
StartDataModel::
nPorts(QtNodes::PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case QtNodes::PortType::In:
		result = 0;
		break;

	case QtNodes::PortType::Out:
		result = 1;

	default:
		break;
	}

	return result;
}

QtNodes::NodeDataType
StartDataModel::
dataType(QtNodes::PortType, QtNodes::PortIndex) const
{
	return ExecutionData().type();
}


std::shared_ptr<QtNodes::NodeData>
StartDataModel::outData(QtNodes::PortIndex)
{
	return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}
