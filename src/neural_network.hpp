#pragma once

#include "layer.hpp"

class NeuralNetwork {

  private:

    std::vector<Layer *> layers;
    double last_error;

  public:

    NeuralNetwork();

    void add_layer(Layer *layer);
    void print();
    std::vector<double> run(std::vector<double> input);
    void train(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs, double learning_rate);
    double get_error(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs);
    void set_input(std::vector<double> input);
    void as_dot();
    double get_last_error();

};
