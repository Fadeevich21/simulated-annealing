#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "libs/simulatedAnnealing/state/State.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;

    static void clearLayout(QLayout *layout) ;

    void drawChessBoard(QGridLayout *layout, int countQueens) ;

    static QLabel *getElementChessBoard(int size, int i, int j, bool hasQueen);

    template<class T1, class T2>
    void drawGraphics(QCustomPlot *plot, std::map<T1, T2> map, QString xLabel, QString yLabel,
                      bool reverseXAxes = false, bool reverseYAxes = false);
};
#endif // MAINWINDOW_H
