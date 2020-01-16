#pragma once

#include "neuron.hpp"


class InputNeuron : public virtual Neuron {

  private:

    double value;

  public:

    InputNeuron(double value);
    ~InputNeuron() =default;

    double get_value() override;

};
