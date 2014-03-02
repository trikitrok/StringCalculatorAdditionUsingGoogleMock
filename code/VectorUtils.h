#pragma once;

#include <vector>
#include <iterator>
#include <algorithm>

namespace VectorUtils {
  template<typename T, typename Function>
  std::vector<T> filter(const std::vector<T> & original, Function pred) {

    std::vector<T> filtered;

    std::copy_if(original.begin(), original.end(),
      std::back_inserter(filtered),
      pred);

    return filtered;
  }
}