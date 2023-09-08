#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

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

    static QLabel *getElementChessBoard(int size, int i, int j) ;
};
#endif // MAINWINDOW_H
