#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    //��ͼ�Ŵ�ۺ���
    void on_toolEnlarge_triggered();
    //������ͼ��С�ۺ���
    void on_toolShrink_triggered();
    //����������вۺ���
    void on_actionAddAll_triggered();
    //���������·�ۺ���
    void on_actionAddLine_triggered();
    //�������վ��ۺ���
    void on_actionAddStation_triggered();
    //����������Ӳۺ���
    void on_actionAddConnect_triggered();
    //�����ı���ʽ��Ӳۺ���
    void on_actionAddByText_triggered();
    //�����鿴������·ͼ�ۺ���
    void on_actionLineMap_triggered();
    //�����Ƿ���ʾ״̬���ۺ���
    void on_actionstatusBar_triggered(bool checked);
    //�����Ƿ���ʾ�������ۺ���
    void on_actiontoolBar_triggered(bool checked);
    //��������Qt�ۺ���
    void on_actionQt_triggered();
    //�����������߲ۺ���
    void on_actionAuthor_triggered();
    //���������˵��ۺ���
    void on_actionuseHelp_triggered();
    //�����رճ���ۺ���
    void on_actionClose_triggered();

    //ʱ����²ۺ���
    void timerUpdate();
    //����б���ͼ�����仯�ۺ���
    void tabWidgetCurrentChanged(int index);
    //�����·���ܺ���
    void addLine();
    //���վ�㹦�ܺ���
    void addStation();
    //������ӹ��ܺ���
    void addConnection();
    //�ı���ʽ��ӹ��ܺ���
    void addByText();
    //���»���ѡ����Ϣ
    void updateTranserQueryInfo();
    //���˳�����·�ı�ۺ���
    void transferStartLineChanged(QString lineName);
    //����Ŀ����·�ı�ۺ���
    void transferDstLineChanged(QString lineNames);
    //���˲�ѯ�ۺ���
    void transferQuery();


protected:
    Ui::MainWindow* ui;             //������UI
    Graphics_view_zoom* myView;     //�Զ�����ͼ�������������
    QGraphicsScene* scene;          //����
    SubwayGraph* subwayGraph;       //��˹�����
    ManageLines* manageLines;       //��ӹ���ǰ�˹�����
    AppHelp* appHelp;               //������ʾ��

    //����·���������ɫ
    QColor getLinesColor(const QList<int>& linesList);
    //�����·������ּ�
    QString getLinesName(const QList<int>& linesList);
    //��վ��ľ�γ�ȵ�������תΪ��ͼ����
    QPointF transferCoord(QPointF coord);
    //��������ͼ�ı�
    void drawEdges(const QList<Edge>& edgesList);
    //��������ͼ��վ��ڵ�
    void drawStations(const QList<int>& stationsList);

private:
    QLabel* statusLabel1, * statusLabel2, * statusLabel3;     //״̬�������ı�
    //�����źźͲۺ���
    void myConnect();
    //��ʼ״̬��
    void initStatusBar();
};

#define LINE_INFO_WIDTH 0   //Ԥ���߿�������Ϣչʾ
#define MARGIN 30           //��ͼ��߾�
#define NET_WIDTH 2000      //����ͼ�����
#define NET_HEIGHT 2000     //����ͼ���߶�
#define SCENE_WIDTH (LINE_INFO_WIDTH+MARGIN*2+NET_WIDTH)    //��ͼ���
#define SCENE_HEIGHT (MARGIN*2+NET_HEIGHT)                  //��ͼ�߶�

#define EDGE_PEN_WIDTH 2    //��·�߿�
#define NODE_HALF_WIDTH 3   //�ڵ��С

#endif // MAINWINDOW_H
