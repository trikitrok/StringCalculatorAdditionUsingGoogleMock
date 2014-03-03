#include "StringCalculator.h"

#include "NumbersExtractor.h"

#include <numeric>

StringCalculator::StringCalculator(NumbersExtractor * numbersExtractor) {
  this->numbersExtractor = numbersExtractor;
}

StringCalculator::~StringCalculator() {
  delete numbersExtractor;
}

int StringCalculator::add(const std::string & numbersSequence) const {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) const {
  return std::accumulate(numbers.begin(), numbers.end(), 0);
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) const {
  return numbersExtractor->extractNumbers(numbersSequence);
}