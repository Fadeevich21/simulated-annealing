#ifndef SIMULATEDANNEALING_TASK_H
#define SIMULATEDANNEALING_TASK_H


#include "../state/State.h"

namespace SimulatedAnnealing {

    class Task {
    public:
        virtual void init(State& state) const = 0;
        virtual int computeEnergy(State& state) const = 0;
    };

}


#endif //SIMULATEDANNEALING_TASK_H
