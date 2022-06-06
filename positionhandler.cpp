#include "positionhandler.h"

PositionHandler::PositionHandler(QObject *parent)
    : QObject{parent}
{

}

QVector<QVector3D*> *PositionHandler::getMapPositons()
{
    return &positions;
}

void PositionHandler::addPosition(QVector3D *pos)
{
    positions.append(pos);
    emit positionChanged();
}

QVector3D *PositionHandler::removePosition(int index)
{
    if(positions.length()>=index)
           return NULL;
    QVector3D *ret = positions.at(index);
    positions.removeAt(index);
    emit positionChanged();
    return ret;
}

void PositionHandler::clear()
{
    positions.clear();
}

PositionHandler::PositionHandler(QObject *parent,const char* name):QObject{parent}
{
    //this->color = new QColor(color);
    this->name = new QString(name);
}

PositionHandler::~PositionHandler()
{
    //delete(color);
    delete(name);
}
