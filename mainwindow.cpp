#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "libs/simulatedAnnealing/solver/Solver.h"
#include "libs/nQueens/task/NQueensTask.h"
#include <iostream>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

    auto start = std::chrono::steady_clock::now();

    QWidget *widget = ui->chessBoardArea->widget();
    ui->chessBoardArea->setWidgetResizable(true);
    QGridLayout *layout = dynamic_cast<QGridLayout *>(widget->layout());
    clearLayout(layout);
    drawChessBoard(layout, countQueens);

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Отрисовка произошла успешно!" << std::endl;
    std::cout << "Время: " << std::chrono::duration<double, std::milli> (diff).count() << " мс" << std::endl;
    std::cout << std::endl;
}

void MainWindow::drawChessBoard(QGridLayout *layout, int countQueens) {
    float minTemperature = ui->minTemperatureValue->value();
    float maxTemperature = ui->maxTemperatureValue->value();
    float alpha = ui->alphaValue->value();
    int countSteps = ui->countStepsValue->value();

    SimulatedAnnealing::Solver solver(minTemperature, maxTemperature, alpha, countSteps);
    solver.setTask(std::make_unique<NQueens::NQueensTask>());

    auto start = std::chrono::steady_clock::now();
    SimulatedAnnealing::State state = solver(countQueens);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Вычисления прошли успешно!" << std::endl;
    std::cout << "Энергия: " << state.getEnergy() << std::endl;
    std::cout << "Время: " << std::chrono::duration<double, std::milli> (diff).count() << " мс" << std::endl;

    ui->energyValue->setText(QString("%1").arg(state.getEnergy()));

    int size = countQueens < 8 ? ui->chessBoardArea->width() / (countQueens + 1) : ui->chessBoardArea->width() / 9;
    for (int i = 0; i < countQueens; i++) {
        for (int j = 0; j < countQueens; j++) {
            QLabel *label = getElementChessBoard(size, i, j, state[i] == j + 1);
            layout->addWidget(label, i, j);
        }
    }
}

QLabel *MainWindow::getElementChessBoard(int size, int i, int j, bool hasQueen) {
    QLabel *label = new QLabel;
    QString color = (i + j) % 2 ? "white" : "black";
    label->setStyleSheet(QString("QLabel { background-color: %1; }").arg(color));
    label->setFixedSize(QSize(size, size));

    if (hasQueen) {
        QPixmap queen(":/resource/img/queen.png");
        queen = queen.scaled(QSize(size * 0.8, size * 0.8));
        label->setPixmap(queen);
    }

    return label;
}

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}
