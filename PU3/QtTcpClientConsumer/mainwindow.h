#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();
  void timerEvent(QTimerEvent *e);
public slots:
  void getData();
  void stop();
  void conecta();
  void disconecta();
  void start();
  void updateList();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int activeTimer =0;
};

#endif // MAINWINDOW_H
