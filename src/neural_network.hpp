#pragma once

#include "layer.hpp"

class NeuralNetwork {

  private:

    std::vector<Layer *> layers;

  public:

    NeuralNetwork() { }

    void add_layer(Layer *layer);
    void print();
    std::vector<double> run(std::vector<double> input);
    void train(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs);

};
