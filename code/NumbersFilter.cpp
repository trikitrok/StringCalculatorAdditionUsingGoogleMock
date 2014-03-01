#include "NumbersFilter.h"

NumbersFilter::NumbersFilter() 
{}

NumbersFilter::~NumbersFilter() 
{}

std::vector<int> NumbersFilter::ignoreTooBig(const std::vector<int> & numbers) const {
  std::vector<int> filteredNumbers;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (notTooBig(numbers[i])) {
      filteredNumbers.push_back(numbers[i]);
    }
  }
  return filteredNumbers;
}

bool NumbersFilter::notTooBig(int number) const {
  return !(number > 1000);
}
