#include <sstream>

#include "util.hpp"
#include "exception.hpp"

double sumsqdiff(std::vector<double> a, std::vector<double> b)
{
  if (a.size() != b.size())
    throw ArgumentError("In sumsqdiff: a and b must be the same size.");


  double rv = 0.0;
  for (size_t i = 0; i < a.size(); i++) {
    double diff = a[i] - b[i];
    rv += diff*diff;
  }

  return rv;
}



std::string vec2string(std::vector<double> vec)
{
  std::stringstream ss;
  ss << "[";
  for (auto v : vec) {
    ss << " " << v;
  }
  ss << " ]";
  std::string rv = ss.str();
  return rv;
}
