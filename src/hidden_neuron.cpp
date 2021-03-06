#include "hidden_neuron.hpp"

namespace sinn {

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
    this->substitute_weights.push_back(weight);
  }
  
  
  void HiddenNeuron::set_activation_function(ActivationFunction *activation_function)
  {
    this->activation_function = activation_function;
  }
  
  
  void HiddenNeuron::swap_weights_and_bias()
  {
    auto temp = this->weights;
    this->weights = this->substitute_weights;
    this->substitute_weights = this->weights;
    double temp_bias = this->bias;
    this->bias = this->substitute_bias;
    this->substitute_bias = temp_bias;
  }
  
  
  double HiddenNeuron::get_substitute_weight(int index)
  {
    return this->substitute_weights[index];
  }

  double HiddenNeuron::get_substitute_bias()
  {
    return this->substitute_bias;
  }
  
  double HiddenNeuron::get_weight(int index)
  {
    return this->weights[index];
  }

  double HiddenNeuron::get_bias()
  {
    return this->bias;
  }
  
  
  void HiddenNeuron::set_substitute_weight(int index, double value)
  {
    this->substitute_weights[index] = value;
  }
  
  
  void HiddenNeuron::set_weight(int index, double value)
  {
    this->weights[index] = value;
  }

  void HiddenNeuron::set_bias(double value)
  {
    this->bias = value;
  }

  void HiddenNeuron::set_substitute_bias(double value)
  {
    this->substitute_bias = value;
  }



} // namespace sinn
