#include "StringCalculator.h"

#include "NumbersSequenceTokenizer.h"
#include "NumbersValidator.h"
#include "NumbersFilter.h"

#include <numeric>

StringCalculator::StringCalculator(
  NumbersSequenceTokenizer * numbersSequenceTokenizer,
  NumbersValidator * numbersValidator,
  NumbersFilter * numbersFilter) {
  this->numbersSequenceTokenizer = numbersSequenceTokenizer;
  this->numbersValidator = numbersValidator;
  this->numbersFilter = numbersFilter;
}

StringCalculator::~StringCalculator() {
  delete numbersSequenceTokenizer;
  delete numbersValidator;
  delete numbersFilter;
}

int StringCalculator::add(const std::string & numbersSequence) const {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) const {
  return std::accumulate(numbers.begin(), numbers.end(), 0);
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) const {
  std::vector<int> numbers = numbersSequenceTokenizer->extractFrom(numbersSequence);
  numbersValidator->validate(numbers);
  return numbersFilter->filter(numbers);
}