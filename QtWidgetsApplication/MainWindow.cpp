#include "mainwindow.h"


#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myView = new Graphics_view_zoom(ui->graphicsView);
    myView->set_modifiers(Qt::NoModifier);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene = new QGraphicsScene;
    scene->setSceneRect(-LINE_INFO_WIDTH, 0, SCENE_WIDTH, SCENE_HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    initStatusBar();

    manageLines = new ManageLines(this);
    subwayGraph = new SubwayGraph;
    appHelp = new AppHelp();

    bool flag = subwayGraph->readFileData(":/data/data/outLine.txt");
    if (!flag)
    {
        QMessageBox box;
        box.setWindowTitle(tr("error information"));
        box.setIcon(QMessageBox::Warning);
        box.setText("读取数据错误!\n将无法展示内置线路！");
        box.addButton(tr("确定"), QMessageBox::AcceptRole);
        if (box.exec() == QMessageBox::Accepted)
        {
            box.close();
        }
    }

    myConnect();

    updateTranserQueryInfo();

    on_actionLineMap_triggered();
}
