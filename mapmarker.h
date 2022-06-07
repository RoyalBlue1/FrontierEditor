#ifndef MAPMARKER_H
#define MAPMARKER_H

#include <QObject>
#include <QMap>
#include <QPointF>
#include <QVector3D>
#include <QVariant>

enum MarkerType {
    Player,
    Sniper,
    MortarTitan,
    MortarSpectre,
    TickReaper,
    PlayerSpawn,
    NPCSpawn,
    Smoke,
    Shop,
    Route
};

static const QMap<MarkerType, QString> nameMap {
    {Player, "Player"},
    {Sniper, "Sniper"},
    {MortarTitan, "Mortar Titan"},
    {MortarSpectre, "Mortar Spectre"},
    {TickReaper, "Tick Reaper"},
    {PlayerSpawn, "Player Spawn"},
    {NPCSpawn, "NPC Spawn"},
    {Smoke, "Smoke"},
    {Shop, "Shop"},
    {Route, "Route"}
};


class MapMarker : public QVariant
{
public:
    MapMarker(QVector3D coords, QPointF minimapCoords, MarkerType type);
    operator QString();
    QVector3D coords();
    QPointF minimapCoords();
    MarkerType type();
    QString typeString();

    void setCoords(QVector3D coords);
    void setMinimapCoords(QPointF minimapCoords);
    void setType(MarkerType type);
private:
    QVector3D m_coords;
    QPointF m_minimapCoords;
    MarkerType m_type;
};

#endif // MAPMARKER_H
