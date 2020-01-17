#include "hidden_neuron.hpp"

#include <iostream>

HiddenNeuron::HiddenNeuron(ActivationFunction *actfunc)
{
  this->activation_function = actfunc;
}

double HiddenNeuron::get_value()
{
  double total = 0.0;
  
  for (size_t i = 0; i < this->in.size(); i++) {
    Neuron *neuron = this->in[i];
    double weight = this->weights[i];
    total += neuron->get_value()*weight;
  }
  return this->activation_function->calculate_value(total);
};


void HiddenNeuron::add_weighted_input(Neuron *neuron, double weight)
{
  this->in.push_back(neuron);
  this->weights.push_back(weight);
}


void HiddenNeuron::set_activation_function(ActivationFunction *activation_function)
{
  this->activation_function = activation_function;
}
