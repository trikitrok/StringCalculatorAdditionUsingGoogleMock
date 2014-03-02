#include "NumbersFilter.h"

#include <algorithm>
#include <iterator>

NumbersFilter::NumbersFilter() 
{}

NumbersFilter::~NumbersFilter() 
{}

bool notTooBig(int number);

std::vector<int> NumbersFilter::ignoreTooBig(const std::vector<int> & numbers) const {
  std::vector<int> filteredNumbers;
  
  std::copy_if(numbers.begin(), numbers.end(),
    std::back_inserter(filteredNumbers),
    notTooBig);

  return filteredNumbers;
}

bool notTooBig(int number) {
  return !(number > 1000);
}
