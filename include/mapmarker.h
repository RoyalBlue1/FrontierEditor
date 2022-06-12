#ifndef MAPMARKER_H
#define MAPMARKER_H

#include <QObject>
#include <QMap>
#include <QPointF>
#include <QVector3D>
#include <QVariant>
#include <QString>
#include <QIcon>
#include "gamemap.h"

enum class MarkerType {
    Player,
    Sniper,
    MortarTitan,
    MortarSpectre,
    TickReaper,
    PlayerSpawn,
    NPCSpawn,
    Smoke,
    Shop,
    Route,
    Prop
};

static const QMap<MarkerType, QString> nameMap {
    {MarkerType::Player, "Player"},
    {MarkerType::Sniper, "Sniper"},
    {MarkerType::MortarTitan, "Mortar Titan"},
    {MarkerType::MortarSpectre, "Mortar Spectre"},
    {MarkerType::TickReaper, "Tick Reaper"},
    {MarkerType::PlayerSpawn, "Player Spawn"},
    {MarkerType::NPCSpawn, "NPC Spawn"},
    {MarkerType::Smoke, "Smoke"},
    {MarkerType::Shop, "Shop"},
    {MarkerType::Route, "Route"},
    {MarkerType::Prop, "Prop"}
};



class MapMarker
{
public:
    MapMarker() = default;
    ~MapMarker() = default;
    MapMarker(const MapMarker &marker) = default;
    MapMarker &operator=(const MapMarker &) = default;
    MapMarker(QVector3D coords, GameMap map, MarkerType type);
    MapMarker(QVector3D coords, QVector3D rotation, GameMap map, MarkerType type);
    operator QString();
    QVector3D coords();
    QVector3D rotation();
    const QPointF minimapCoords();
    const MarkerType type();
    const QString typeString();
    static QPointF convertCoords(QVector3D coords, GameMap map);

    void setCoords(QVector3D coords);
    void setRotation(QVector3D rotation);
    void setType(MarkerType type);


private:
    QVector3D m_coords;
    QVector3D m_rotation;
    QPointF m_minimapCoords;
    MarkerType m_type;
    GameMap m_map;
};

Q_DECLARE_METATYPE(MapMarker);

#endif // MAPMARKER_H
