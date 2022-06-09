#include "mainwindow.h"
#include "ui_mainwindow.h"

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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    auto flow = new QtNodes::FlowScene(registerDataModels(),this);
    ui->gridLayout->addWidget(new QtNodes::FlowView(flow));

}

MainWindow::~MainWindow()
{
    delete ui;
}




