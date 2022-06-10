#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "positionmodel.h"
#include "startdatamodel.h"

static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto flow = new QtNodes::FlowScene(registerDataModels(),this);
    ui->waveTabs->addTab(new QtNodes::FlowView(flow), "Wave 1");
    positionModel = new PositionModel();
    positionModel->populateTest();
    GameMap gameMap = GameMap::ForwardbaseKodai;
    ui->markerListView->setModel(positionModel);
    markerSelectionModel = ui->markerListView->selectionModel();
    connect(markerSelectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::onMenuSelect);
    ui->minimapGraphicsView->setMap(gameMap);
    ui->minimapGraphicsView->setModel(positionModel);

    connect(ui->minimapGraphicsView, &MinimapGraphicsView::markerClicked, ui->markerListView, &QListView::setCurrentIndex);

    auto marker = MapMarker{QVector3D(3372.88f, 1420.11f, 3466.55f),
            gameMap,
            MarkerType::TickReaper
    };
    positionModel->addMarker(marker);
    ui->markerGroupBox->setDisabled(true);

    auto iter = nameMap.constBegin();
    auto end = nameMap.constEnd();
    while (iter != end) {
        ui->typeComboBox->addItem(iter.value());
        iter++;
    }
    ui->typeComboBox->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<QtNodes::DataModelRegistry>();
    ret->registerModel<StartDataModel>("Start");


    return ret;
}

void MainWindow::onMenuSelect(const QItemSelection &selected, const QItemSelection & )
{
    if (!selected.empty()) {
        ui->markerGroupBox->setDisabled(false);
        MapMarker marker = qvariant_cast<MapMarker>(positionModel->data(markerSelectionModel->currentIndex(), Qt::UserRole));
        ui->typeComboBox->setCurrentIndex(std::distance(nameMap.begin(), nameMap.find(marker.type())));
        ui->xCoordSpinBox->setValue(marker.coords().x());
        ui->yCoordSpinBox->setValue(marker.coords().y());
        ui->zCoordSpinBox->setValue(marker.coords().z());
    }
    else {
        ui->markerGroupBox->setDisabled(true);
    }
}

//void MainWindow::onMinimapSelect(QModelIndex index) {

//}
