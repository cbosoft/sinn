#include <iostream>
#include <sstream>

#include "../sinn.hpp"
#include "../test.hpp"

int main(int argc, const char **argv)
{
  (void) argc;
  test_header(argv[0]);

  sinn::NeuralNetwork nn = sinn::NeuralNetwork();
  nn.add_layer(new sinn::InputLayer(4), 0.1);
  nn.add_layer(new sinn::OutputLayer(1), 0.1);

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

  std::vector<std::vector<double>> checking_inputs = {
    { 5,  6,  7,  8},
    { 6,  7,  8,  9},
    { 7,  8,  9, 10},
    { 8,  9, 10, 11}
  };

  std::vector<std::vector<double>> checking_outputs = {
    {9},
    {10},
    {11},
    {12}
  };



  double learning_rate = 0.1;
  double tolerance = 0.5;
  int epochs = 10000;

  for (int i = 0; i < epochs && nn.get_last_error() > tolerance; i++) {
    nn.train(training_inputs, training_outputs, learning_rate);
    //auto input = training_inputs[0];
    //std::vector<double> output = nn(input);
    //std::cout << i << ": " << vec2string(input) << " -> " << vec2string(output) << ", err: " << nn.get_last_error() << std::endl;
  }

  // for (size_t i = 0; i < training_inputs.size(); i++) {
  //   auto input = training_inputs[i];
  //   std::vector<double> output = nn(input);
  //   std::cout << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << " (" << sinn::util::vec2string(training_outputs[i]) << ")" << std::endl;
  // }
  // for (size_t i = 0; i < checking_inputs.size(); i++) {
  //   auto input = checking_inputs[i];
  //   std::vector<double> output = nn(input);
  //   std::cout << sinn::util::vec2string(input) << " -> " << sinn::util::vec2string(output) << " (" << sinn::util::vec2string(checking_outputs[i]) << ")" << std::endl;
  // }
  // std::cout << nn.get_error(checking_inputs, checking_outputs) << std::endl;
  // std::cout << nn.get_last_error() << std::endl;

  test_check_and_exit(nn.get_error(checking_inputs, checking_outputs) < tolerance);
}
