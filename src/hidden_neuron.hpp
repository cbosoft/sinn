#pragma once

#include "neuron.hpp"
#include "activation_functions/activation_function.hpp"

class NeuralNetwork;
class HiddenNeuron : public Neuron {

  private:

    std::vector<Neuron *> in;
    std::vector<double> weights;
    std::vector<double> next_weights;
    ActivationFunction *activation_function;

  public:
    
    HiddenNeuron(ActivationFunction *actfunc);
    ~HiddenNeuron() =default;

    double get_value() override;
    void add_weighted_input(Neuron *neuron, double weight);
    void set_activation_function(ActivationFunction *activation_function);
    void swap_weights();

    friend NeuralNetwork;

};
