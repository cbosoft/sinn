#pragma once

#include "layer.hpp"

class NeuralNetwork {

  private:

    std::vector<Layer *> layers;

  public:

    NeuralNetwork() { }

    void add_layer(Layer *layer);
    void print();

};
