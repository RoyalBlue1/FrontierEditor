#include "enddatamodel.h"

EndDataModel::EndDataModel() {}

unsigned int EndDataModel::nPorts(QtNodes::PortType portType) const
{
	unsigned int result = 1;

	switch (portType)
	{
	case QtNodes::PortType::In:
		result = 1;
		break;

	case QtNodes::PortType::Out:
		result = 0;

	default:
		break;
	}

	return result;
}

QtNodes::NodeDataType EndDataModel::dataType(QtNodes::PortType, QtNodes::PortIndex) const
{
	return ExecutionData().type();
}
