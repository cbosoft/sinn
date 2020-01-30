#pragma once

#include <string>

#include "layer.hpp"

namespace sinn {

  class NeuralNetwork {

    private:

      std::vector<Layer *> layers;
      double last_error;

    public:

      NeuralNetwork();


      // nn_print.cpp
      void print();

      // train.cpp
      void train(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs, double learning_rate, double dWeight=1e-5);
      double get_error(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs);

      // nn_dot.cpp
      void as_dot(std::string filename) const;

      // neural_network.cpp
      void add_layer(Layer *layer, double weight);
      void set_input(std::vector<double> input);
      double get_last_error() const;
      std::vector<double> get_output() const;
      std::vector<double> get_output(std::vector<double> input);

      std::vector<double> operator()(std::vector<double> input)
      {
        return this->get_output(input);
      }

  };

} // namespace sinn
