#include <iostream>

#include "neural_network.hpp"
#include "hidden_layer.hpp"
#include "input_layer.hpp"
#include "output_layer.hpp"

int main(void)
{
  NeuralNetwork nn = NeuralNetwork();
  nn.add_layer(new InputLayer({0.1, 0.2, 0.3}));
  nn.add_layer(new OutputLayer(2));
  std::vector<std::vector<double>> training_inputs = {
    {1, 1, 1},
    {2, 2, 2},
    {3, 3, 3},
    {4, 4, 4}
  };
  std::vector<std::vector<double>> training_outputs = {
    {3, 3},
    {6, 6},
    {9, 9},
    {12, 12}
  };

  nn.set_input(training_inputs[0]);
  nn.print();

  for (int i = 0; i < 10000 && nn.get_last_error() > 5e-2; i++) {
    nn.train(training_inputs, training_outputs, 0.01);
    nn.set_input(training_inputs[0]);
    nn.print();
  }

  for (size_t i = 0; i < training_inputs.size(); i++) {
    nn.set_input(training_inputs[i]);
    nn.print();
    std::cout << "Expected output:" << std::endl;
    for (size_t j = 0; j < training_outputs[i].size(); j++)
      std::cout << "  " << training_outputs[i][j] << std::endl;
  }
}
