#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
    void timerEvent(QTimerEvent *e);
  
  void tcpConnect(QString s);
public slots:
  void putData();
  void conecta();
  void start();
  void stop();
  void disconecta();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int ActiveTimerID=0;
};

#endif // MAINWINDOW_H
