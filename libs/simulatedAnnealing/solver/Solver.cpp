#include "Solver.h"
#include <cstdlib>
#include <cmath>

#define RAND_RANGE(l, r) (l + rand() % (r - l + 1))
#define RAND_RANGE_REAL(l, r) (((double) rand() / RAND_MAX) * (r - l) + l)

namespace SimulatedAnnealing {

    Solver::Solver(float minTemperature, float maxTemperature, float alpha, int countSteps)
            : minTemperature(minTemperature), maxTemperature(maxTemperature), alpha(alpha), countSteps(countSteps) {

    }

    void Solver::setTask(std::unique_ptr<Task> task_) {
        task = std::move(task_);
    }

    State Solver::operator()(std::size_t size) const {
        State workingState(size);

        task->init(workingState);
        workingState.setEnergy(task->computeEnergy(workingState));

        State bestState = workingState;
        State currentState = workingState;

        float temperature = maxTemperature;
        while (temperature >= minTemperature) {
            if (temperature != 0) {
                for (int step = 0; step < countSteps; step++) {
                    int x = RAND_RANGE(0, size - 1);
                    int y;
                    do {
                        y = RAND_RANGE(0, size - 1);
                    } while (y == x);

                    std::swap(workingState[x], workingState[y]);
                    workingState.setEnergy(task->computeEnergy(workingState));

                    if (workingState.getEnergy() < bestState.getEnergy()) {
                        bestState = workingState;
                        currentState = workingState;
                    } else if (workingState.getEnergy() < currentState.getEnergy()) {
                        currentState = workingState;
                    } else {
                        float p = std::exp(
                                -std::abs(currentState.getEnergy() - workingState.getEnergy()) / temperature);
                        float p1 = RAND_RANGE_REAL(0.0, 1.0);
                        if (p1 <= p) {
                            currentState = workingState;
                        }
                    }

                    workingState = currentState;
                }
            }

            temperature *= alpha;
        }

        return bestState;
    }

}