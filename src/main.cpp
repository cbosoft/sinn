#include <iostream>

#include "sinn.hpp"
#include "util.hpp"

int main(void)
{
  NeuralNetwork nn = NeuralNetwork();
  nn.add_layer(new InputLayer(5));
  nn.add_layer(new OutputLayer(1));

  std::vector<std::vector<double>> training_inputs = {
    {1, 2, 3, 4},
    {2, 3, 4, 5},
    {3, 4, 5, 6},
    {4, 5, 6, 7}
  };

  std::vector<std::vector<double>> training_outputs = {
    {5},
    {6},
    {7},
    {8}
  };

  std::cout << vec2string(nn(training_inputs[0])) << std::endl;
  exit(0);

  double learning_rate = 0.1;
  double tolerance = 5e-2;
  int epochs = 30;

  for (int i = 0; i < epochs /*&& nn.get_last_error() > tolerance*/; i++) {
    nn.train(training_inputs, training_outputs, learning_rate);
    auto input = training_inputs[0];
    std::vector<double> output = nn(input);
    std::cout << i << ": " << vec2string(input) << " -> " << vec2string(output) << ", err: " << nn.get_last_error() << std::endl;
  }

  for (size_t i = 0; i < training_inputs.size(); i++) {
    auto input = training_inputs[i];
    std::vector<double> output = nn(input);
    std::cout << vec2string(input) << " -> " << vec2string(output) << " (" << vec2string(training_outputs[i]) << ")" << std::endl;
  }
}
