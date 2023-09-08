#include "State.h"

namespace SimulatedAnnealing {

    State::State(std::size_t size)
            : state(std::vector<int>(size, 0)) {

    }

    std::vector<int> State::getState() const {
        return state;
    }

    int State::getEnergy() const {
        return energy;
    }

    std::size_t State::getStateSize() const {
        return state.size();
    }

    void State::setEnergy(int energy_) {
        energy = energy_;
    }

    int &State::operator[](int index) {
        return state[index];
    }

}