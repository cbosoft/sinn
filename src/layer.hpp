#pragma once

#include <vector>
#include "neuron.hpp"

class NeuralNetwork;
class Layer {

  protected:

    std::vector<Neuron *> neurons;

  public:

    Layer() =default;
    virtual ~Layer();

    void add_neuron(Neuron *neuron);
    void clear_neurons();

    friend NeuralNetwork;

};
