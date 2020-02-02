#include <sstream>
#include <random>

#include "util.hpp"
#include "exception.hpp"

static std::random_device rd;
static std::mt19937 mt_gen(rd());

namespace sinn {

  namespace util {

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

    double get_uniform_random(double min, double max)
    {
      std::uniform_real_distribution<> uniform_distribution(min, max);
      return uniform_distribution(mt_gen);
    }

    double get_normal_random(double mean, double stddev)
    {
      std::normal_distribution<> normal_distribution{mean,stddev};
      return normal_distribution(mt_gen);
    }

  } // namespace util

} // namespace sinn
