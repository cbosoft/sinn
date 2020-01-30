#include <sstream>
#include <random>

#include "util.hpp"
#include "exception.hpp"

static std::random_device rd;
static std::mt19937 mt_gen(rd());
static std::uniform_real_distribution<> uniform_distribution(0.0, 1.0);
static std::normal_distribution<> normal_distribution{1.0,1.0};

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

    double get_uniform_random()
    {
      return uniform_distribution(mt_gen);
    }

    double get_normal_random()
    {
      return normal_distribution(mt_gen);
    }

  } // namespace util

} // namespace sinn
