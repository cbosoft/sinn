#pragma once

#include "hidden_layer.hpp"


class OutputLayer : public HiddenLayer {

  public:

    OutputLayer(int n) : HiddenLayer(n) {}

    std::vector<double> get_output();

};
