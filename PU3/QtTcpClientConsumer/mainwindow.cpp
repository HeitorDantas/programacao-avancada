#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>
#include <vector>


using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

}

void MainWindow::tcpConnect(){
    socket->connectToHost(ui->lineEdit->text(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";

    }
    else{
        qDebug() << "Disconnected";
    }
}

void MainWindow::getData(){
    QString str,getstr;
    QByteArray array;
    QStringList list;
    qint64 thetime;
    std::vector<qint64> time;
    std::vector<int> value;

    if(ui->listWidget->count() == 0)
        getstr = "get " + ui->lineEdit->text() + " 30\r\n";
    else
        getstr = "get " + ui->listWidget->selectedItems().at(0)->text() + " 30\r\n";
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write(getstr.toStdString().c_str());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    time.push_back(thetime);
                    value.push_back(str.toInt(&ok));

                    //qDebug() << thetime << ": " << str;
                }
            }//end while
            ui->myPlotter->receiveData(value,time);
        }
    }
}


MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
void MainWindow::conecta(){
    tcpConnect();

}
void MainWindow::disconecta(){
    socket->disconnectFromHost();

}

void MainWindow::start(){
    if(activeTimer == 0)
        activeTimer  = startTimer(ui->horizontalSliderTime->value()*1000);
    //getData();
}

void MainWindow::stop(){
    killTimer(activeTimer);
    activeTimer =0;

}
void MainWindow::updateList(){
    QString str;
    QList<QListWidgetItem *> listRequest;
    socket->write("list\n\r");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    ui->listWidget->clear();
    qDebug() << socket->bytesAvailable();
    while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        ui->listWidget->addItem(str);

    }
}

void MainWindow::timerEvent(QTimerEvent *e){
    getData();
}
