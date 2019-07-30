#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

class Plotter : public QWidget
{
    Q_OBJECT
public:

    explicit Plotter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);

    void receiveData(std::vector<int> value,std::vector<qint64> time);
signals:

public slots:

private:
    std::vector<int> valuesVec;
    std::vector<qint64> timeVec;


};




#endif // PLOTTER_H
