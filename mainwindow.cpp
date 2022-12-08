#include "mainwindow.h"
#include "drawingwidget.h"
#include "ui_mainwindow.h"
#include "world.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(screenWidth,screenHeight);

    QHBoxLayout* layout = new QHBoxLayout{ui->drawingFrame};
    drawing = new DrawingWidget{world, ui->drawingFrame};
    layout->addWidget(drawing);

    timer.start(timeBetweenUpdates, this);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    world.update();

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
