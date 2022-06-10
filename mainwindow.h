#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelectionModel>

#include "nodes/NodeData.hpp"
#include "nodes/FlowScene.hpp"
#include "nodes/FlowView.hpp"
#include "nodes/ConnectionStyle.hpp"
#include "nodes/TypeConverter.hpp"
#include "nodes/DataModelRegistry.hpp"
#include "positionmodel.h"
#include "nodes/ConnectionStyle.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onMenuSelect(const QItemSelection &selected, const QItemSelection &deselected);
//    void onMinimapSelect(const QModelIndex index);
private:
    Ui::MainWindow *ui;
    PositionModel *positionModel;
    QItemSelectionModel *markerSelectionModel;
};
#endif // MAINWINDOW_H
