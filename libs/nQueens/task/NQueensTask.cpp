#include "NQueensTask.h"
#include <climits>

namespace NQueens {

    bool inRange(int l, int r, int value) {
        return value >= l && value <= r;
    }

    void NQueensTask::init(SimulatedAnnealing::State &state) const {
        state.setEnergy(INT_MAX);
        for (int i = 0; i < state.getStateSize(); i++) {
            state[i] = i + 1;
        }
    }

    int NQueensTask::computeEnergy(SimulatedAnnealing::State &state) const {
        std::vector<std::pair<int, int>> d = {
                {-1, -1},
                {-1, 1},
                {1,  -1},
                {1,  1},
        };

        int energy = 0;
        for (int i = 0; i < state.getStateSize(); i++) {
            int x = i;
            int y = state[i];
            for (auto &element: d) {
                int tmpX = x + element.first;
                int tmpY = y + element.second;

                while (true) {
                    if (!inRange(0, state.getStateSize() - 1, tmpX) ||
                        !inRange(1, state.getStateSize(), tmpY)) {
                        break;
                    }

                    energy += state[tmpX] == tmpY;

                    tmpX += element.first;
                    tmpY += element.second;
                }
            }
        }

        return energy;
    }

}
