#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <iomanip>

class Neuron {

  protected:

    std::vector<Neuron *> in;
    std::vector<Neuron *> out;

  public:

    Neuron() = default;
    virtual ~Neuron() = default;

    virtual double get_value() 
    {
      // throw error
      return 0.0;
    };

    virtual void add_input(Neuron *neuron)
    {
      this->in.push_back(neuron);
    }
  
    void add_output(Neuron *neuron)
    {
      this->out.push_back(neuron);
    }

};

class HiddenNeuron : public virtual Neuron {

  private:

    std::vector<double> weights;

  public:

    HiddenNeuron() = default;
    ~HiddenNeuron() override = default;

    void add_input(Neuron *neuron) override
    {
      this->in.push_back(neuron);
      this->weights.push_back(0.1); // TODO initialise weights
    }
  
    double get_value() override
    {
      double total = 0.0;
      
      assert(this->in.size() == this->weights.size());
  
      for (size_t i = 0; i < this->in.size(); i++) {
        Neuron *neuron = this->in[i];
        double weight = this->weights[i];
        total += neuron->get_value()*weight;
      }
      return total;
    }

};

class InputNeuron : public virtual Neuron {

  private:

    double value;

  public:

    ~InputNeuron() override = default;

    InputNeuron(double value)
    {
      this->value = value;
    }

    double get_value() override
    {
      return this->value;
    }
};

class Layer {


  public:

    std::vector<Neuron *> neurons;
    
    Layer() = default;

    ~Layer()
    {
      this->clear_neurons();
    }
  
    void add_neuron(Neuron *neuron)
    {
      this->neurons.push_back(neuron);
    }

    void clear_neurons()
    {
      for (size_t i = 0; i < this->neurons.size(); i++)
      {
        delete this->neurons[i];
      }
    }

};

class InputLayer : public virtual Layer {

  public:

    InputLayer(std::vector<double> input_values)
    {
      this->generate_neurons(input_values);
    }


    void generate_neurons(std::vector<double> input_values)
    {
      for (auto value : input_values)
      {
        InputNeuron *n = new InputNeuron(value);
        this->add_neuron(n);
      }
    }

};

class HiddenLayer : public virtual Layer {

  public:

    HiddenLayer(int n)
    {
      this->generate_neurons(n);
    }


    void generate_neurons(int n)
    {
      for (int i = 0; i < n; i++)
      {
        HiddenNeuron *n = new HiddenNeuron();
        this->add_neuron(n);
      }
    }

};

class OutputLayer : public virtual HiddenLayer {

  public:

    OutputLayer(int n) : HiddenLayer(n) {}

    std::vector<double> get_output()
    {
      std::vector<double> rv;

      for (auto n : this->neurons)
        rv.push_back(n->get_value());

      return rv;
    }

};



class NeuralNetwork {

  private:

    std::vector<Layer *> layers;

  public:

    NeuralNetwork() { }

    void add_layer(Layer *layer)
    {
      this->layers.push_back(layer);

      size_t nlayers = this->layers.size();
      if (nlayers > 1) {
        for (auto penult : this->layers[nlayers-2]->neurons) {
          for (auto ult : this->layers[nlayers-1]->neurons) {
            penult->add_output(ult);
            ult->add_input(penult);
          }
        }
      }
    } 

    void print()
    {

      // TODO: column
      size_t neuron_index = 0;
      bool finished = false;
      const int col_width = 10;

      // for (size_t layer_index = 0; layer_index < this->layers.size(); layer_index++) {
      //   std::cout << std::setw(col_width);
      // }
      // std::cout << std::endl;
      for (size_t layer_index = 0; layer_index < this->layers.size(); layer_index++) {
        std::stringstream ss;
        ss << "Layer " << layer_index;
        std::cout << std::setw(col_width) << ss.str() << "  ";
      }
      std::cout << std::endl;

      while (!finished) {

        finished = true;
        for (auto layer: this->layers)
          if (neuron_index < layer->neurons.size())
            finished = false;

        if (finished)
          break;

        for (auto layer : this->layers) {
          if (neuron_index < layer->neurons.size()) {
            std::cout << std::setw(col_width) << layer->neurons[neuron_index]->get_value() << "  ";
          }
          else {
            std::cout << std::setw(col_width) << "-" << "  ";
          }
        }
        neuron_index++;
        std::cout << std::endl << std::endl;
      }
    }

};


int main(void)
{
  NeuralNetwork nn = NeuralNetwork();
  nn.add_layer(new InputLayer({0.1, 0.2, 0.3}));
  nn.add_layer(new HiddenLayer(4));
  nn.add_layer(new HiddenLayer(3));
  nn.add_layer(new OutputLayer(2));

  nn.print();
}
