#include <iostream>

#include "neural_network.hpp"
#include "hidden_neuron.hpp"
#include "output_layer.hpp"
#include "util.hpp"

namespace sinn {

  void NeuralNetwork::train(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs, double learning_rate, double dWeight)
  {
    double initial_error = this->get_error(training_inputs, training_outputs);
    for (size_t layer_index = 1; layer_index < this->layers.size(); layer_index++) {
      auto layer = this->layers[layer_index];
  
      for (auto _neuron : layer->neurons) {
        HiddenNeuron *neuron = ((HiddenNeuron *)_neuron);
  
        for (size_t weight_index = 0; weight_index < neuron->weights.size(); weight_index++) {
  
          double weight_before = neuron->weights[weight_index];
          neuron->weights[weight_index] += dWeight;
          double dError = this->get_error(training_inputs, training_outputs) - initial_error;
          neuron->weights[weight_index] = weight_before; // done in this way to prevent possible floating point errors introduced by adding and subtracting
  
          double gradient = (dError == 0) ? 0 : dWeight/dError;
          //double gradient = dWeight/dError;
          //std::cout << dError << "  " << gradient  << std::endl;
          neuron->set_substitute(weight_index, neuron->weights[weight_index] - (learning_rate * (gradient)));
  
        }
  
      }
    }
  
  
    for (size_t layer_index = 1; layer_index < this->layers.size(); layer_index++) {
      auto layer = this->layers[layer_index];
  
      for (auto _neuron : layer->neurons)
        ((HiddenNeuron *)_neuron)->swap_weights();
  
    }
  
    this->get_error(training_inputs, training_outputs);
    //std::cerr << this->last_error << std::endl;
  }
  
  double NeuralNetwork::get_error(std::vector<std::vector<double>> training_inputs, std::vector<std::vector<double>> training_outputs)
  {
  
    if (training_inputs.size() != training_outputs.size()) {
      std::cerr << "net::get_error: training dataset inputs must match size of outputs." << std::endl;
    }
  
    double total_error = 0.0;
    for (size_t set_index = 0; set_index < training_inputs.size(); set_index++) {
      auto input = training_inputs[set_index];
      auto output = training_outputs[set_index];
      std::vector<double> value = this->get_output(input);
      total_error += sinn::util::sumsqdiff(value, output);
    }
  
    this->last_error = total_error;
    return total_error;
  }


} // namespace sinn
