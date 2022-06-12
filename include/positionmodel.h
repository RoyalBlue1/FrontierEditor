#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

#include "mapmarker.h"
#include <QAbstractListModel>
#include <QVector3D>
#include <QIcon>



class PositionModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PositionModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QList<MapMarker> getMarkers();
    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    std::pair<MapMarker, QModelIndex> getClosest(QPointF point);
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
public slots:
    void addMarker(MapMarker marker);

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void populateTest();

private:
    QList<MapMarker> m_markerList;
    QMap<MarkerType, QIcon> m_iconMap;
};

#endif // POSITIONMODEL_H
