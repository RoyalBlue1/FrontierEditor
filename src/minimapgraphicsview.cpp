#include "minimapgraphicsview.h"
#include "util.h"

MinimapGraphicsView::MinimapGraphicsView(QWidget *parent):
	QGraphicsView(parent)
{
	m_scene = new QGraphicsScene(this);
	setScene(m_scene);
	show();
	m_markerTypePixmap = {
		{MarkerType::Player, QPixmap(":/assets/icons/compass_icon_friendly_pilot.png")},
		{MarkerType::Sniper, QPixmap(":/assets/icons/fd_icon_northstar.png")},
		{MarkerType::MortarTitan, QPixmap(":/assets/icons/fd_icon_titan_mortar.png")},
		{MarkerType::MortarSpectre, QPixmap(":/assets/icons/fd_icon_spectre_mortar.png")},
		{MarkerType::TickReaper, QPixmap(":/assets/icons/fd_icon_reaper.png")},
		//        {MarkerType::PlayerSpawn, QPixmap(":/assets/icons/.png")},
		{MarkerType::NPCSpawn, QPixmap(":/assets/icons/fd_icon_grunt.png")},
		//        {MarkerType::Smoke, QPixmap(":/assets/icons/.png")},
		{MarkerType::Shop, QPixmap(":/assets/icons/bh_bonus_icon.png")},
		//        {MarkerType::Route, QPixmap(":/assets/icons/.png")}
	};

}

MinimapGraphicsView::~MinimapGraphicsView()
{
	delete m_scene;
}

void MinimapGraphicsView::setMap(GameMap name)
{
	m_mapName = mapFileNames[name];
	m_mapImage = QPixmap(":/assets/maps/" + m_mapName + ".png");	// Load from .qrc
	m_scene->clear();	// Clear everything
	scale(m_minScale, m_minScale);
	m_scene->addPixmap(m_mapImage);
}

void MinimapGraphicsView::setModel(PositionModel *model)
{
    m_positionModel = model;
    auto markers = model->getMarkers();
    for (MapMarker marker : markers) {
        QPointF coords = marker.minimapCoords();
        QPixmap pixmap = m_markerTypePixmap[marker.type()];
        QGraphicsPixmapItem *item = m_scene->addPixmap(pixmap);
        item->setScale(0.4);
        item->moveBy(coords.x(), coords.y());
        item->setOffset(-item->boundingRect().width()/2, -item->boundingRect().height()/2);
        m_markerPixmapList.append(item);
    }
    connect(m_positionModel, &PositionModel::rowsInserted, this, &MinimapGraphicsView::markersAdded);
    connect(m_positionModel, &PositionModel::rowsRemoved, this, &MinimapGraphicsView::markersRemoved);
    connect(m_positionModel, &PositionModel::dataChanged, this, &MinimapGraphicsView::markersUpdated);

}

void MinimapGraphicsView::markersAdded(const QModelIndex &, int first, int last)
{
	for (int i = first; i < last; i++) {
		MapMarker marker = qvariant_cast<MapMarker>(m_positionModel->data(m_positionModel->index(i), Qt::UserRole));
		auto coords = marker.minimapCoords();
		QPixmap pixmap = m_markerTypePixmap[marker.type()];
		QGraphicsPixmapItem *item = m_scene->addPixmap(pixmap);

        item->setScale(0.4);
        item->setPos(coords.x(), coords.y());
        m_markerPixmapList.append(item);
    }
}

void MinimapGraphicsView::markersRemoved(const QModelIndex &parent, int first, int last)
{
	qDebug() << parent << first << last;
}

void MinimapGraphicsView::markersUpdated(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &)
{
    qDebug() << topLeft << bottomRight;
    for (int i = topLeft.row(); i <= bottomRight.row(); i++) {
        MapMarker marker = qvariant_cast<MapMarker>(m_positionModel->data(m_positionModel->index(i), Qt::UserRole));
        auto coords = marker.minimapCoords();

        QGraphicsPixmapItem *item = m_markerPixmapList[i];

        item->setPos(coords.x(), coords.y());

        item->setPixmap(m_markerTypePixmap[marker.type()]);
    }
}

//void MinimapGraphicsView::removeMarker(int index)
//{
//    if (index < markers.size() && index > 0)
//    {
//        markers.removeAt(index);
//    }
//}



void MinimapGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers().testAnyFlag(Qt::ControlModifier))
    {
        int angle = event->angleDelta().y();
        QTransform tr = transform();
        float scale = 1;
        if (angle > 0)
        {
            // Scroll up
            scale = 1.1f;
        }
        else if (angle < 0)
        {
            // Scroll Down
            scale = 0.9f;
        }
        tr.scale(scale, scale);

		// Clamp scale btwn 1 and 50

        if (tr.m11() < m_minScale) {
            tr.scale(m_minScale / tr.m11(), m_minScale / tr.m22());
            setTransform(tr);
            for (auto marker: m_markerPixmapList) {
                marker->setScale(0.4);
            }
            return;
        }
        else if (tr.m11() > 50){
            tr.scale(50 / tr.m11(), 50 / tr.m22());
            setTransform(tr);
            return;
        }
        setTransform(tr);

		for (auto marker: m_markerPixmapList) {
			marker->setScale(1/scale * marker->scale());
		}
	}
	else
	{
		QGraphicsView::wheelEvent(event);
	}
}

void MinimapGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !event->modifiers().testAnyFlag(Qt::ShiftModifier))
    {
        QPointF clickPos = mapToScene(event->pos()); // Mouse click to scene coords (0-512, 0-512)
        auto pair = m_positionModel->getClosest(clickPos);
        qreal scale = transform().m11();

		if (distance(pair.first.minimapCoords(), clickPos) < 15 * 1/scale)
			emit markerClicked(pair.second);
	}
	else
	{
		QGraphicsView::mousePressEvent(event);
	}
}

void MinimapGraphicsView::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Shift:
		setDragMode(DragMode::ScrollHandDrag);
		break;
	default:
		QGraphicsView::keyPressEvent(event);
	}
}

void MinimapGraphicsView::keyReleaseEvent(QKeyEvent *event)

{
	switch (event->key()) {
	case Qt::Key_Shift:
		setDragMode(DragMode::NoDrag);
		setCursor(QCursor(Qt::CrossCursor));
	default:
		QGraphicsView::keyPressEvent(event);
	}

}
