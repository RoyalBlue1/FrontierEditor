#pragma once

#include "nodes/NodeDataModel.hpp"

using QtNodes::NodeDataType;
using QtNodes::NodeData;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class EntityData : public NodeData
{
public:

    EntityData()
    {}

    EntityData(QStringList entitys)
    : _entitys(entitys)
    {}

    NodeDataType type() const override
    {
    return NodeDataType {"entitys",
                         "Entitys",QColor(255,0,0)};
    }

    QStringList entitys() const
    { return _entitys; }

    QString entitysAsText() const
    {
      QString ret;
      for( const auto& i:_entitys)
          ret+=i+QString("\n");
      return ret;
    }

private:

    QStringList _entitys;
};
