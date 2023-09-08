#ifndef SIMULATEDANNEALING_SOLVER_H
#define SIMULATEDANNEALING_SOLVER_H


#include <memory>
#include "../state/State.h"
#include "../task/Task.h"

namespace SimulatedAnnealing {

    class Solver {
    private:
        float minTemperature;
        float maxTemperature;
        float alpha;
        int countSteps;

        std::unique_ptr<Task> task;

    public:
        Solver(float minTemperature, float maxTemperature, float alpha, int countSteps);

        void setTask(std::unique_ptr<Task> task_);

        State operator()(std::size_t size) const;
    };

}


#endif //SIMULATEDANNEALING_SOLVER_H
