#include "hidden_layer.hpp"
#include "activation_functions/lrelu.hpp"
//#include "activation_functions/identity.hpp"

namespace sinn {

  HiddenLayer::HiddenLayer(int n)
  {
    this->generate_neurons(n);
  }
  
  void HiddenLayer::generate_neurons(int n)
  {
    this->clear_neurons();
    for (int i = 0; i < n; i++) {
      //ActivationFunction *actfunc = new ActFunc_Identity();
      ActivationFunction *actfunc = new ActFunc_LeakyReLu(0.01);
      this->neurons.push_back(new HiddenNeuron(actfunc));
    }
  }

} // namespace sinn
