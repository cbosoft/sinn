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
}
