#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->chessBoardArea->setFixedSize(300, 300);
    ui->chessBoardContents->setLayout(new QGridLayout(this));

    QWidget *widget = new QWidget();
    widget->setLayout(ui->chessBoardContents->layout());
    ui->chessBoardArea->setWidget(widget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked() {
    int countQueens = ui->countQueensValue->value();
    if (countQueens == 0) {
        return;
    }

    QWidget *widget = ui->chessBoardArea->widget();
    ui->chessBoardArea->setWidgetResizable(true);
    QGridLayout *layout = dynamic_cast<QGridLayout *>(widget->layout());
    clearLayout(layout);
    drawChessBoard(layout, countQueens);

    ui->chessBoardArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->chessBoardArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void MainWindow::drawChessBoard(QGridLayout *layout, int countQueens) {
    int size = countQueens < 8 ? ui->chessBoardArea->width() / (countQueens + 1) : ui->chessBoardArea->width() / 8;
    for (int i = 0; i < countQueens; i++) {
        for (int j = 0; j < countQueens; j++) {
            QLabel *label = getElementChessBoard(size, i, j);
            layout->addWidget(label, i, j);
        }
    }
}

QLabel *MainWindow::getElementChessBoard(int size, int i, int j) {
    QLabel *label = new QLabel;
    QString color = (i + j) % 2 ? "white" : "black";
    label->setStyleSheet(QString("QLabel { background-color: %1; }").arg(color));
    label->setFixedSize(QSize(size, size));

    QPixmap queen(":/resource/img/queen.png");
    queen = queen.scaled(QSize(size * 0.8, size * 0.8));
    label->setPixmap(queen);

    return label;
}

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}
