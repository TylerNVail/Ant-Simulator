#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "world.h"

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class DrawingWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent *event) override;

private:
    Ui::MainWindow *ui;
    DrawingWidget* drawing{nullptr};
    World world;
    QBasicTimer timer;

    double screenWidth{1000};
    double screenHeight{600};
    int timeBetweenUpdates{15};
};
#endif // MAINWINDOW_H
