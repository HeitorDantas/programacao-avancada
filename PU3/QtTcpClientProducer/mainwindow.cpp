#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);



}

void MainWindow::tcpConnect(QString s){
  socket->connectToHost(s,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;
  int numRand;
  if(socket->state()== QAbstractSocket::ConnectedState){
    numRand = qrand();
    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " +
          QString::number((numRand)%(ui->horizontalSliderMax->value() -
          ui->horizontalSliderMin->value()+1) +
          ui->horizontalSliderMin->value()) +"\r\n";

     // qDebug() << str;
      socket->write(str.toStdString().c_str());
      ui->textBrowser->append(str.toStdString().c_str());
     // if(socket->waitForBytesWritten(3000)){
        //qDebug() << "wrote";
     // }
  }
}

void MainWindow::conecta()
{

    tcpConnect(ui->lineEdit->text());
}

void MainWindow::start()

{
    if(ActiveTimerID == 0)
        this->ActiveTimerID = startTimer(ui->horizontalSlider_3->value() *1000);
    else{
        ui->textBrowser->setTextColor(QColor(255,0,0));
        ui->textBrowser->append("Ja existe um timer ativo!\n");
        ui->textBrowser->setTextColor(QColor(0,0,0));
    }
    qDebug() << ActiveTimerID;
}

void MainWindow::stop()
{
    //para o timer

    killTimer(this->ActiveTimerID);
    ActiveTimerID = 0;
}

void MainWindow::disconecta()
{
   socket->disconnectFromHost();
}

MainWindow::~MainWindow(){
  delete socket;
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(ui->horizontalSliderMin->value() > ui->horizontalSliderMax->value()){
        ui->horizontalSliderMin->setValue(ui->horizontalSliderMax->value());
        qDebug() << "O valor minimo tem que ser menor ou igual ao maximo\n";
    }
    putData();

}
