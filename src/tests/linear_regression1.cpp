#include <iostream>

#include "../sinn.hpp"
#include "../test.hpp"

int main(int argc, const char **argv)
{
  (void) argc;
  test_header(argv[0]);
  sinn::NeuralNetwork nn = sinn::NeuralNetwork();
  nn.add_layer_normal(new sinn::InputLayer(1), 1.0, 0.5);
  nn.add_layer_normal(new sinn::OutputLayer(1), 1.0, 0.5);

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

  std::vector<std::vector<double>> checking_inputs = {
    {5},
    {6},
    {7},
    {8}
  };

  std::vector<std::vector<double>> checking_outputs = {
    {15},
    {18},
    {21},
    {24}
  };

  double learning_rate = 10;
  double tolerance = 0.5;
  int epochs = 10000;

  for (int i = 0; i < epochs && nn.get_last_error() > tolerance*0.1; i++) {
    nn.train(training_inputs, training_outputs, learning_rate);
    // auto input = training_inputs[0];
    // std::vector<double> output = nn(input);
    // std::cout << i << ": " << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << ", err: " << nn.get_last_error() << std::endl;
  }

  // for (size_t i = 0; i < training_inputs.size(); i++) {
  //   auto input = training_inputs[i];
  //   auto check = training_outputs[i];
  //   std::vector<double> output = nn(input);
  //   std::cout << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << " (" << sinn::util::vec2string(check) << ")" << std::endl;
  // }
  // for (size_t i = 0; i < checking_inputs.size(); i++) {
  //   auto input = checking_inputs[i];
  //   auto check = checking_outputs[i];
  //   std::vector<double> output = nn(input);
  //   std::cout << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << " (" << sinn::util::vec2string(check) << ")" << std::endl;
  // }
  // std::cout << nn.get_error(checking_inputs, checking_outputs) << std::endl;
  // std::cout << nn.get_last_error() << std::endl;

  test_check_and_exit(nn.get_error(checking_inputs, checking_outputs) < tolerance);
}

