#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "startdatamodel.h"
static std::shared_ptr<QtNodes::DataModelRegistry> registerDataModels();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto flow = new QtNodes::FlowScene(registerDataModels(),this);
    ui->gridLayout->addWidget(new QtNodes::FlowView(flow));

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
