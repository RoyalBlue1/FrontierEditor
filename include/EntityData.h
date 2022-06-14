#pragma once

#include "nodes/NodeDataModel.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class EntityData : public NodeData
{
  public:
	EntityData() {}

	EntityData(QStringList entities) : _entities(entities) {}

	NodeDataType type() const override
	{
		return NodeDataType {"entities", "Entities", QColor(255, 0, 0)};
	}

	QStringList entities() const
	{
		return _entities;
	}

	QString entitiesAsText() const
	{
		QString ret;
		for (const auto& i : _entities)
			ret += i + QString("\n");
		return ret;
	}

  private:
	QStringList _entities;
};
