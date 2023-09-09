
#ifndef SIMULATEDANNEALING_STATE_H
#define SIMULATEDANNEALING_STATE_H


#include <vector>
#include <map>

namespace SimulatedAnnealing {

    class State {
    private:
        std::vector<int> state;
        int energy{};

    public:
        std::map<float, int> dependenceBestEnergyOnTemperature;
        std::map<float, int> dependenceCountTakeBadSolutionsOnTemperature;
        std::map<int, float> dependenceTemperatureOnIteration;

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
