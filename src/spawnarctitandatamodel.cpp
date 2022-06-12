#include "spawnarctitandatamodel.h"

SpawnArcTitanDataModel::SpawnArcTitanDataModel()
{

}

unsigned int
SpawnArcTitanDataModel::
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
SpawnArcTitanDataModel::
dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
  switch(portType)
  {
  case QtNodes::PortType::In:
      return ExecutionData().type();
  case QtNodes::PortType::Out:
      if(portIndex == 0)
          return EntityData().type();
      else
          return ExecutionData().type();
  }
  return NodeDataType();
}
std::shared_ptr<QtNodes::NodeData>
SpawnArcTitanDataModel::outData(QtNodes::PortIndex portIndex)
{
    if(portIndex == 0)
        return std::static_pointer_cast<QtNodes::NodeData>(_entities);
    else
        return std::static_pointer_cast<QtNodes::NodeData>(_execution);
}

void SpawnArcTitanDataModel::setInData(std::shared_ptr<QtNodes::NodeData> data, int, const QUuid& connectionId)
{

}

