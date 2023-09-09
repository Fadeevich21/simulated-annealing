#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "libs/simulatedAnnealing/solver/Solver.h"
#include "libs/nQueens/task/NQueensTask.h"
#include <iostream>
#include <chrono>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->chessBoardContents->setLayout(new QGridLayout(this));

    auto *widget = new QWidget();
    widget->setLayout(ui->chessBoardContents->layout());
    ui->chessBoardArea->setWidget(widget);
    ui->chessBoardArea->setWidgetResizable(true);
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
    auto *layout = dynamic_cast<QGridLayout *>(widget->layout());
    clearLayout(layout);
    drawChessBoard(layout, countQueens);

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Отрисовка произошла успешно!" << std::endl;
    std::cout << "Время: " << std::chrono::duration<double, std::milli>(diff).count() << " мс" << std::endl;
    std::cout << std::endl;
}

void MainWindow::drawChessBoard(QGridLayout *layout, int countQueens) {
    auto minTemperature = (float) ui->minTemperatureValue->value();
    auto maxTemperature = (float) ui->maxTemperatureValue->value();
    auto alpha = (float) ui->alphaValue->value();
    int countSteps = ui->countStepsValue->value();

    SimulatedAnnealing::Solver solver(minTemperature, maxTemperature, alpha, countSteps);
    solver.setTask(std::make_unique<NQueens::NQueensTask>());

    auto start = std::chrono::steady_clock::now();
    SimulatedAnnealing::State state = solver(countQueens);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Вычисления прошли успешно!" << std::endl;
    std::cout << "Энергия: " << state.getEnergy() << std::endl;
    std::cout << "Время: " << std::chrono::duration<double, std::milli>(diff).count() << " мс" << std::endl;

    ui->energyValue->setText(QString("%1").arg(state.getEnergy()));

    drawGraphics(ui->graphicsEnergyToTemperature, state.dependenceBestEnergyOnTemperature, "Температура",
                 "Лучшая энергия", true);
    drawGraphics(ui->graphicsCountTakeBadSolutionsToTemperature, state.dependenceCountTakeBadSolutionsOnTemperature,
                 "Температура", "Число принятых плохих решений", true);
    drawGraphics(ui->graphicsTemperatureOnIteration, state.dependenceTemperatureOnIteration, "Итерация", "Температура");

    int size = countQueens < 8 ? ui->chessBoardArea->width() / (countQueens + 1) : ui->chessBoardArea->width() / 9;
    for (int i = 0; i < countQueens; i++) {
        for (int j = 0; j < countQueens; j++) {
            QLabel *label = getElementChessBoard(size, i, j, state[i] == j + 1);
            layout->addWidget(label, i, j);
        }
    }
}

QLabel *MainWindow::getElementChessBoard(int size, int i, int j, bool hasQueen) {
    static QPixmap queen = (new QPixmap(":/resource/img/queen.png"))->scaled(size * 0.8, size * 0.8);

    auto label = new QLabel;
    QString color = (i + j) % 2 ? "white" : "black";
    label->setStyleSheet(QString("QLabel { background-color: %1; }").arg(color));
    label->setFixedSize(size, size);

    if (hasQueen) {
        label->setPixmap(queen);
    }

    return label;
}

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        child->widget()->deleteLater();
        delete child;
    }
}

template<class T1, class T2>
void MainWindow::drawGraphics(QCustomPlot *plot, std::map<T1, T2> map, QString xLabel, QString yLabel,
                              bool reverseXAxes, bool reverseYAxes) {
    plot->clearGraphs();
    plot->addGraph();
    plot->rescaleAxes(true);

    QVector<double> keys, values;
    for (auto &element: map) {
        keys.push_back(element.first);
        values.push_back(element.second);
    }

    plot->xAxis->setLabel(xLabel);
    plot->yAxis->setLabel(yLabel);

    double minKey = *std::min_element(keys.begin(), keys.end());
    double maxKey = *std::max_element(keys.begin(), keys.end());
    plot->xAxis->setRange(minKey, maxKey);
    plot->xAxis->setRangeReversed(reverseXAxes);

    double minValue = *std::min_element(values.begin(), values.end());
    double maxValue = *std::max_element(values.begin(), values.end());
    plot->yAxis->setRange(minValue, maxValue);
    plot->yAxis->setRangeReversed(reverseYAxes);

    plot->graph(0)->setData(keys, values);

    plot->replot();
}
