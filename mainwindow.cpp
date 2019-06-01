#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
//int inic_timer=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // timer -> stop();
    ui->setupUi(this);

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300);

    QPen mypen = QPen(Qt::black);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LefLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF ButtonLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(LefLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(ButtonLine,mypen);

    int ItemCount = 1;

    for(int i = 0;i < ItemCount; i++)
        {

            particula *item = new particula();
            scene->addItem(item);

        }

    timer = new QTimer(this);
    timer->start(50);
   // cuenta++;

    if(inic_timer==0){
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
}
}


MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_pushButton_clicked()
{
    inic_timer=1;
}

