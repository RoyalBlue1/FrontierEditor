#include "positionmodel.h"
#include "util.h"

PositionModel::PositionModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_iconMap = {
        {MarkerType::Player, QIcon(":/assets/icons/compass_icon_friendly_pilot.png")},
        {MarkerType::Sniper, QIcon(":/assets/icons/fd_icon_northstar.png")},
        {MarkerType::MortarTitan, QIcon(":/assets/icons/fd_icon_titan_mortar.png")},
        {MarkerType::MortarSpectre, QIcon(":/assets/icons/fd_icon_spectre_mortar.png")},
        {MarkerType::TickReaper, QIcon(":/assets/icons/fd_icon_reaper.png")},
        //        {MarkerType::PlayerSpawn, QIcon(":/assets/icons/.png")},
        {MarkerType::NPCSpawn, QIcon(":/assets/icons/fd_icon_grunt.png")},
        //        {MarkerType::Smoke, QIcon(":/assets/icons/.png")},
        {MarkerType::Shop, QIcon(":/assets/icons/bh_bonus_icon.png")},
        //        {MarkerType::Route, QIcon(":/assets/icons/.png")}
    };
}


int PositionModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return m_markerList.size();
}

QVariant PositionModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    MapMarker marker = m_markerList[index.row()];

    switch (role) {
    case Qt::DisplayRole:
        return marker.typeString();
        break;
    case Qt::UserRole:
        return QVariant::fromValue(marker);
        break;
    case Qt::DecorationRole:
        return QIcon(m_iconMap[marker.type()]);
    case Qt::EditRole | PositionRoles::TypeRole:
        return QVariant::fromValue(marker.type());
    case Qt::EditRole | PositionRoles::PositionRole:
        return marker.coords();
    case Qt:: EditRole | PositionRoles::RotationRole:
        return marker.rotation();
    }

    return QVariant();
}

QList<MapMarker> PositionModel::getMarkers()
{
    return m_markerList;
}

bool PositionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QVariant item = data(index, role);
    if (item != value && item.canConvert(value.metaType())) {
        // FIXME: Implement me!

        switch (role) {
            case Qt::EditRole | PositionRoles::TypeRole:
                m_markerList[index.row()].setType(qvariant_cast<MarkerType>(value));
            case Qt::EditRole | PositionRoles::PositionRole:
                m_markerList[index.row()].setCoords(qvariant_cast<QVector3D>(value));
            case Qt:: EditRole | PositionRoles::RotationRole:
                m_markerList[index.row()].setRotation(qvariant_cast<QVector3D>(value));
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

std::pair<MapMarker, QModelIndex> PositionModel::getClosest(QPointF point)
{
    std::vector<int> indicies(m_markerList.size());

    std::generate(indicies.begin(), indicies.end(), [i = -1]() mutable
    {
        return ++i;
    });	// vector of[0...n] of markers list indicies

    std::sort(indicies.begin(), indicies.end(), [&list = m_markerList, point](const int a, const int b)
    {
        // sort index vector
        return distance(list[a].minimapCoords(), point) < distance(list[b].minimapCoords(), point);
    });
    //    qDebug() << indicies;
    return std::make_pair(m_markerList[indicies[0]], index(indicies[0]));
}

Qt::ItemFlags PositionModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

void PositionModel::addMarker(MapMarker marker)
{
    int lastRow = m_markerList.size();
    beginInsertRows(index(lastRow), lastRow, lastRow+1);
    m_markerList.append(marker);
    endInsertRows();
}

bool PositionModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    m_markerList.remove(row, count);
    endRemoveRows();
    return true;
}

void PositionModel::populateTest()
{
    beginResetModel();

    MapMarker marker(QVector3D(-2128.12f,-2562, 25),
                     GameMap::ForwardbaseKodai,	//TODO: Mapping from game to image, note scaling and transformation
                     MarkerType::Sniper
                     );

    m_markerList.append(marker);
    // Testing code
    MapMarker marker1 { QVector3D(-1414.29f, 908.461f, 1464.03f),
                GameMap::ForwardbaseKodai,
                MarkerType::MortarSpectre
                      };

    m_markerList.append(marker1);

    MapMarker marker2 { QVector3D(-3297.99f, 833.893f, 1016.03f),
                GameMap::ForwardbaseKodai,
                MarkerType::Shop
                      };

    m_markerList.append(marker2);
    endResetModel();

}


