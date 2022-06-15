#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "positionmodel.h"
#include "startdatamodel.h"
#include "spawnarctitandatamodel.h"
#include "spawnnuketitandatamodel.h"
#include "waitfordeathdatamodel.h"
#include "splitexecutiondatamodel.h"
#include "enddatamodel.h"

static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels()
{
	auto ret = std::make_shared<QtNodes::DataModelRegistry>();

	ret->registerModel<StartDataModel>("Control Events");
	ret->registerModel<SplitExecutionDataModel>("Control Events");
	ret->registerModel<EndDataModel>("Control Events");

	ret->registerModel<SpawnArcTitanDataModel>("Spawn Events");
	ret->registerModel<SpawnNukeTitanDataModel>("Spawn Events");

	ret->registerModel<WaitForDeathDataModel>("Wait Events");
	return ret;
}

static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels();
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QtNodes::ConnectionStyle::setConnectionStyle(
		R"(
	{
	  "ConnectionStyle": {
		"UseDataDefinedColors": true

	  }
	}
	)");
	auto flow = new QtNodes::FlowScene(registerDataModels(), this);
	ui->waveTabs->addTab(new QtNodes::FlowView(flow), "Wave 1");
	positionModel = new PositionModel();
	positionModel->populateTest();
	GameMap gameMap = GameMap::ForwardbaseKodai;
	ui->markerListView->setModel(positionModel);
	markerSelectionModel = ui->markerListView->selectionModel();
	connect(markerSelectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::onMarkerSelect);
	ui->minimapGraphicsView->setMap(gameMap);
	ui->minimapGraphicsView->setModel(positionModel);

	connect(ui->minimapGraphicsView, &MinimapGraphicsView::markerClicked, ui->markerListView, &QListView::setCurrentIndex);

	auto marker = MapMarker {QVector3D(3372.88f, 1420.11f, 3466.55f), gameMap, MarkerType::TickReaper};
	positionModel->addMarker(marker);
	ui->markerGroupBox->setDisabled(true);

	auto iter = nameMap.constBegin();
	auto end = nameMap.constEnd();
	iter++;
	while (iter != end)
	{
		ui->typeComboBox->addItem(iter.value(), QVariant::fromValue(iter.key()));
		iter++;
	}
	ui->typeComboBox->setCurrentIndex(-1);
	connect(ui->typeComboBox, &QComboBox::currentIndexChanged, this, [this]() {
		QModelIndex index = markerSelectionModel->currentIndex();
		positionModel->setData(index, ui->typeComboBox->currentData(), Qt::EditRole | PositionRoles::TypeRole);
	});
	connect(ui->xCoordSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onPositionChange);
	connect(ui->yCoordSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onPositionChange);
	connect(ui->zCoordSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onPositionChange);

	connect(ui->xRotSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onRotationChange);
	connect(ui->yRotSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onRotationChange);
	connect(ui->zRotSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::onRotationChange);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onMarkerSelect(const QItemSelection& selected, const QItemSelection&)
{
	if (!selected.empty())
	{
		ui->markerGroupBox->setDisabled(false);
		MapMarker marker = qvariant_cast<MapMarker>(markerSelectionModel->currentIndex().data(Qt::UserRole));
		ui->typeComboBox->setCurrentIndex(std::distance(nameMap.begin(), nameMap.find(marker.type())) - 1);
		ui->xCoordSpinBox->setValue(marker.coords().x());
		ui->yCoordSpinBox->setValue(marker.coords().y());
		ui->zCoordSpinBox->setValue(marker.coords().z());

		ui->xRotSpinBox->setValue(marker.rotation().x());
		ui->yRotSpinBox->setValue(marker.rotation().y());
		ui->zRotSpinBox->setValue(marker.rotation().z());
	}
	else
	{
		ui->markerGroupBox->setDisabled(true);
	}
}

void MainWindow::onPositionChange(double)
{
	QVector3D vector(ui->xCoordSpinBox->value(), ui->yCoordSpinBox->value(), ui->zCoordSpinBox->value());

	QModelIndex index = markerSelectionModel->currentIndex();
	positionModel->setData(index, vector, Qt::EditRole | PositionRoles::PositionRole);
}

void MainWindow::onRotationChange(double)
{
	QVector3D vector(ui->xRotSpinBox->value(), ui->yRotSpinBox->value(), ui->zRotSpinBox->value());

	QModelIndex index = markerSelectionModel->currentIndex();
	positionModel->setData(index, vector, Qt::EditRole | PositionRoles::RotationRole);
}
