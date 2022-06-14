#ifndef MINIMAPGRAPHICSVIEWH_H
#define MINIMAPGRAPHICSVIEWH_H

#include "mapmarker.h"
#include "positionmodel.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QVector3D>
#include <QVector2D>

class MinimapGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MinimapGraphicsView(QWidget *parent = 0);
    ~MinimapGraphicsView();

    void setMap(GameMap name);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);
    void setModel(PositionModel *model);

signals:
    void markerClicked(QModelIndex &index);

private slots:
    void markersAdded(const QModelIndex &parent, int first, int last);
    void markersRemoved(const QModelIndex &parent, int first, int last);
    void markersUpdated(const QModelIndex &topLeft, const QModelIndex &bottomRight,
                                    const QList<int> &roles = QList<int>());
private:
    QGraphicsScene *m_scene;
    QPixmap m_mapImage;
    QString m_mapName;
    const float m_minScale = 450. / 1024.;
    PositionModel *m_positionModel;
    QMap<MarkerType, QPixmap> m_markerTypePixmap;
    QList<QGraphicsPixmapItem *> m_markerPixmapList;
};

#endif // MINIMAPGRAPHICSVIEWH_H
