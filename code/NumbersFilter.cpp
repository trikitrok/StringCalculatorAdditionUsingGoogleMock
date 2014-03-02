#include "NumbersFilter.h"

#include "VectorUtils.h"

NumbersFilter::NumbersFilter() 
{}

NumbersFilter::~NumbersFilter() 
{}

std::vector<int> NumbersFilter::ignoreTooBig(const std::vector<int> & numbers) const {
  return VectorUtils::filter(numbers, [](int number) { return !(number > 1000); });
}