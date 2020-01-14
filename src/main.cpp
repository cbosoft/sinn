#include <iostream>
#include <vector>
#include <pair>

class Neuron {
  
private:
  
  std::vector<std::pair<Neuron *, double>> in; // neurons and weights
  std::vector<Neuron *> out;
  
public:

  Neuron()
  {
  }

  void add_input(Neuron *neuron)
  {
    this->in.push_back(neuron);
  }

  void add_output(Neuron *neuron)
  {
    this->out.push_back(neuron);
  }

  double get_value()
  {
    double total = 0.0;
    for (auto &pair : this->in) {
      auto neuron = pair.first;
      auto weight = pair.second;
      total += neuron->get_value()*weight;
    }
    return ;
  }

};

class Layer {

private:

  std::vector<Neuron *> neurons;

public:
  
  Layer()
  {
  }
  
};


int main(void)
{
  std::cout << "hello, world" << std::endl;
}
