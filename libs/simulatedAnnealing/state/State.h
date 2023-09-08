
#ifndef SIMULATEDANNEALING_STATE_H
#define SIMULATEDANNEALING_STATE_H


#include <vector>

namespace SimulatedAnnealing {

    class State {
    private:
        std::vector<int> state;
        int energy{};

    public:
        explicit State(std::size_t size);

        [[nodiscard]] std::vector<int> getState() const;
        [[nodiscard]] int getEnergy() const;
        [[nodiscard]] std::size_t getStateSize() const;

        void setEnergy(int energy_);
        int& operator[](int index);
    };

}


#endif //SIMULATEDANNEALING_STATE_H
