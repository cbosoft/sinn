#pragma once

#include <vector>

class Neuron {

  public:

    Neuron() =default;
    virtual ~Neuron() =default;

    virtual double get_value() =0;
};
