#include "startdatamodel.h"

StartDataModel::StartDataModel()
{

}

unsigned int
StartDataModel::
nPorts(PortType portType) const
{
  unsigned int result = 1;

  switch (portType)
  {
    case PortType::In:
      result = 0;
      break;

    case PortType::Out:
      result = 1;

    default:
      break;
  }

  return result;
}
QJsonObject
StartDataModel::
save() const
{
  QJsonObject modelJson = NodeDataModel::save();


  return modelJson;
}


void
StartDataModel::
restore(QJsonObject const &p)
{

}

std::shared_ptr<NodeData>
StartDataModel::outData(PortIndex)
{
    st
}
