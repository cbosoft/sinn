#include <iostream>

#include "sinn.hpp"
#include "test.hpp"

int main(void)
{
  test_header("1. linear-regression");
  sinn::NeuralNetwork nn = sinn::NeuralNetwork();
  nn.add_layer(new sinn::InputLayer(1), 0.1);
  nn.add_layer(new sinn::OutputLayer(1), 0.1);

  std::vector<std::vector<double>> training_inputs = {
    {1},
    {2},
    {3},
    {4}
  };

  std::vector<std::vector<double>> training_outputs = {
    {3},
    {6},
    {9},
    {12}
  };

  double learning_rate = 10;
  double tolerance = 5e-2;
  int epochs = 30;

  for (int i = 0; i < epochs && nn.get_last_error() > tolerance; i++) {
    nn.train(training_inputs, training_outputs, learning_rate);
    //auto input = training_inputs[0];
    //std::vector<double> output = nn(input);
    //std::cout << i << ": " << vec2string(input) << " -> " << vec2string(output) << ", err: " << nn.get_last_error() << std::endl;
  }

  // for (size_t i = 0; i < training_inputs.size(); i++) {
  //   auto input = training_inputs[i];
  //   std::vector<double> output = nn(input);
  //   std::cout << vec2string(input) << " -> " << vec2string(output) << " (" << vec2string(training_outputs[i]) << ")" << std::endl;
  // }

  test_check_and_exit(nn.get_last_error() < tolerance);
}

