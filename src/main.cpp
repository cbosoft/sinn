#include "neural_network.hpp"
#include "hidden_layer.hpp"
#include "input_layer.hpp"
#include "output_layer.hpp"

int main(void)
{
  NeuralNetwork nn = NeuralNetwork();
  nn.add_layer(new InputLayer({0.1, 0.2, 0.3}));
  nn.add_layer(new HiddenLayer(4));
  nn.add_layer(new HiddenLayer(3));
  nn.add_layer(new OutputLayer(2));

  nn.print();

  std::vector<std::vector<double>> training_inputs = {
    {0.1, 0.1, 0.1},
    {0.2, 0.2, 0.2},
    {0.3, 0.3, 0.3},
    {0.4, 0.4, 0.4}
  };
  std::vector<std::vector<double>> training_outputs = {
    {0.3, 0.3},
    {0.6, 0.6},
    {0.9, 0.9},
    {1.2, 1.2}
  };

  for (int i = 0; i < 10000; i++)
    nn.train(training_inputs, training_outputs, 0.1);

  nn.print();
}
