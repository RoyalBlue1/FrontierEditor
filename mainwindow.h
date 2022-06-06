#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nodes/NodeData.hpp"
#include "nodes/FlowScene.hpp"
#include "nodes/FlowView.hpp"
#include "nodes/ConnectionStyle.hpp"
#include "nodes/TypeConverter.hpp"
#include "nodes/DataModelRegistry.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
