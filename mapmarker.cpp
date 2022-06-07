#include "mapmarker.h"

MapMarker::MapMarker(QVector3D coords, QPointF minimapCoords, MarkerType type)
{
    m_coords = coords;
    m_minimapCoords = minimapCoords;
    m_type = type;
}

MapMarker::operator QString()
{
    QString worldCoords =  QString("X:%1 Y:%2 Z:%3").arg(QString::number(m_coords.x()), QString::number(m_coords.y()), QString::number(m_coords.z()));
    QString mapCoords =  QString("X:%1 Y:%2").arg(QString::number(m_minimapCoords.x()), QString::number(m_minimapCoords.y()));

    return QString("MapMarker| World coords: %1 | Minimap %2 | Type %3").arg(worldCoords, mapCoords, nameMap[m_type]);
}

QVector3D MapMarker::coords()
{
    return m_coords;
}

QPointF MapMarker::minimapCoords()
{
    return m_minimapCoords;
}

MarkerType MapMarker::type()
{
    return m_type;
}

QString MapMarker::typeString()
{
    return nameMap[m_type];
}

void MapMarker::setCoords(QVector3D coords)
{
    m_coords = coords;
}

void MapMarker::setMinimapCoords(QPointF minimapCoords)
{
    m_minimapCoords = minimapCoords;
}

void MapMarker::setType(MarkerType type)
{
    m_type = type;
}
