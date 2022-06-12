#include "mapmarker.h"

MapMarker::MapMarker(QVector3D coords, GameMap map, MarkerType type)
{
    m_coords = coords;
    m_map = map;
    m_minimapCoords = convertCoords(coords, map);
    m_type = type;
}

MapMarker::operator QString()
{
    QString worldCoords =  QString("X:%1 Y:%2 Z:%3").arg(QString::number(m_coords.x()), QString::number(m_coords.y()), QString::number(m_coords.z()));
    QString mapCoords =  QString("X:%1 Y:%2").arg(QString::number(m_minimapCoords.x()), QString::number(m_minimapCoords.y()));

    return QString("MapMarker| World coords: %1 | Minimap %2 | Type %3").arg(worldCoords, mapCoords, nameMap[m_type]);
}

QPointF MapMarker::convertCoords(QVector3D coords, GameMap map) {
    float x = coords.x();
    float y = coords.y();
    const auto transform = transformMap.at(map);
    x = abs(x - transform[0])/transform[2];
    y = abs(y - transform[1])/transform[2];
    return QPointF(x, y);
}

QVector3D MapMarker::coords()
{
    return m_coords;
}

const QPointF MapMarker::minimapCoords()
{
    return m_minimapCoords;
}

const MarkerType MapMarker::type()
{
    return m_type;
}

const QString MapMarker::typeString()
{
    return nameMap[m_type];
}

void MapMarker::setCoords(QVector3D coords)
{
    m_coords = coords;
}

void MapMarker::setType(MarkerType type)
{
    m_type = type;
}
