#pragma once

#include "neuron.hpp"


class InputNeuron : public Neuron {

  private:

    double value;

  public:

    InputNeuron(double value);
    ~InputNeuron() =default;

    double get_value() override;
    void set_value(double value);

};
