#include <iostream>

#include "sinn.hpp"

int main(void)
{
  sinn::NeuralNetwork nn = sinn::NeuralNetwork();
  nn.add_layer(new sinn::InputLayer(5), 1.0);
  nn.add_layer(new sinn::OutputLayer(1), 1.0);

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

  std::cout << sinn::util::vec2string(nn(training_inputs[0])) << std::endl;
  exit(0);

  double learning_rate = 0.1;
  //double tolerance = 5e-2;
  int epochs = 30;

  for (int i = 0; i < epochs /*&& nn.get_last_error() > tolerance*/; i++) {
    nn.train(training_inputs, training_outputs, learning_rate);
    auto input = training_inputs[0];
    std::vector<double> output = nn(input);
    std::cout << i << ": " << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << ", err: " << nn.get_last_error() << std::endl;
  }

  for (size_t i = 0; i < training_inputs.size(); i++) {
    auto input = training_inputs[i];
    std::vector<double> output = nn(input);
    std::cout << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << " (" << sinn::util::vec2string(training_outputs[i]) << ")" << std::endl;
  }
}
