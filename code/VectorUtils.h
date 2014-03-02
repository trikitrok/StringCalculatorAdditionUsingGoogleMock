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

  template<typename T2, typename T1, typename Function>
  std::vector<T2> map(const std::vector<T1> & original, Function f) {

    std::vector<T2> mapped;

    std::transform(original.begin(), original.end(),
      std::back_inserter(mapped),
      f);

    return mapped;
  }

  template<typename T>
  void append(std::vector<T> & appendedTo, const std::vector<T> & appended) {
    appendedTo.insert(appendedTo.end(), appended.begin(), appended.end());
  }
}