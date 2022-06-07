#ifndef EXECUTIONDATA_H
#define EXECUTIONDATA_H

#include "nodes/NodeDataModel.hpp"

using QtNodes::NodeDataType;
using QtNodes::NodeData;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class ExecutionData : public NodeData
{
public:

    ExecutionData()
    {}

    NodeDataType type() const override
    {
    return NodeDataType {"execution",
                         "Execution",QColor(0,255,0)};
    }

    int execution() const
    { return 1; } //will contain data of previous object



private:

};

#endif // EXECUTIONDATA_H
