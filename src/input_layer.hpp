#pragma once

#include "input_neuron.hpp"
#include "layer.hpp"


class InputLayer : public virtual Layer {

  public:

    InputLayer(std::vector<double> input_values);
    ~InputLayer() =default;

    void generate_neurons(std::vector<double> input_values);
};
