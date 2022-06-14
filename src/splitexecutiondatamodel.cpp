#include "splitexecutiondatamodel.h"

SplitExecutionDataModel::SplitExecutionDataModel()
{

}

unsigned int
SplitExecutionDataModel::
nPorts(QtNodes::PortType portType) const
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

QtNodes::NodeDataType
SplitExecutionDataModel::
dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
	return ExecutionData().type();
}
std::shared_ptr<QtNodes::NodeData>
SplitExecutionDataModel::outData(QtNodes::PortIndex portIndex)
{

	return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}
