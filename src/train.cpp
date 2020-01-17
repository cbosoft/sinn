#include <iostream>

#include "neural_network.hpp"
#include "hidden_neuron.hpp"
#include "input_neuron.hpp"
#include "output_layer.hpp"

void NeuralNetwork::train(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs, double learning_rate)
{
  /*
    For each neuron:
      calculate gradient and shift weight

    "calculate gradient"... wrt the whole error? Or just for one input? Its gotta be the whole thing, right?
   */

  double initial_error = this->get_error(training_inputs, training_outputs);
  for (size_t layer_index = 1; layer_index < this->layers.size(); layer_index++) {
    auto layer = this->layers[layer_index];

    for (auto _neuron : layer->neurons) {
      HiddenNeuron *neuron = ((HiddenNeuron *)_neuron);

      double dWeight = 1e-2;
      for (size_t weight_index = 0; weight_index < neuron->weights.size(); weight_index++) {
        neuron->weights[weight_index] += dWeight;
        double dError = this->get_error(training_inputs, training_outputs) - initial_error;
        neuron->weights[weight_index] -= dWeight;
        neuron->next_weights[weight_index] = neuron->weights[weight_index] - (learning_rate * (dWeight/dError));
      }

    }
  }


  for (size_t layer_index = 1; layer_index < this->layers.size(); layer_index++) {
    auto layer = this->layers[layer_index];

    for (auto _neuron : layer->neurons)
      ((HiddenNeuron *)_neuron)->swap_weights();

  }

  std::cerr << this->last_error << std::endl;
}

void NeuralNetwork::set_input(std::vector<double> input)
{
  for (size_t i = 0; i < input.size(); i++) {
    ((InputNeuron *)this->layers[0]->neurons[i])->set_value(input[i]);
  }
}

double sumsqdiff(std::vector<double> a, std::vector<double> b)
{
  if (a.size() != b.size()) {
    std::cerr << "sumsqdiff: vectors must match size." << std::endl;
  }


  double rv = 0.0;
  for (size_t i = 0; i < a.size(); i++) {
    double diff = a[i] - b[i];
    rv += diff*diff;
  }

  return rv;
}

double NeuralNetwork::get_error(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs)
{
  double total_error = 0.0;

  if (training_inputs.size() != training_outputs.size()) {
    std::cerr << "net::get_error: training dataset inputs must match size of outputs." << std::endl;
  }

  for (size_t set_index = 0; set_index < training_inputs.size(); set_index++) {
    auto input = training_inputs[set_index];
    auto output = training_outputs[set_index];
    this->set_input(input);

    std::vector<double> value = ((OutputLayer *)this->layers[this->layers.size()-1])->get_output();
    total_error = sumsqdiff(value, output);
  }

  this->last_error = total_error;
  return total_error;
}
