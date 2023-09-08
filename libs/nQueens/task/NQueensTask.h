#ifndef SIMULATEDANNEALING_NQUEENSTASK_H
#define SIMULATEDANNEALING_NQUEENSTASK_H


#include "../../simulatedAnnealing/task/Task.h"

namespace NQueens {

    class NQueensTask : public SimulatedAnnealing::Task {
    public:
        void init(SimulatedAnnealing::State& state) const override;
        int computeEnergy(SimulatedAnnealing::State& state) const override;
    };

}


#endif //SIMULATEDANNEALING_NQUEENSTASK_H
