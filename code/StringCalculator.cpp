#include "StringCalculator.h"

#include "NumbersExtractor.h"
#include "NumbersValidator.h"
#include "NumbersFilter.h"

StringCalculator::StringCalculator(
  NumbersExtractor * numberExtractor,
  NumbersValidator * numbersValidator,
  NumbersFilter * numbersFilter) {
  this->numberExtractor = numberExtractor;
  this->numbersValidator = numbersValidator;
  this->numbersFilter = numbersFilter;
}

StringCalculator::~StringCalculator() {
  delete numberExtractor;
  delete numbersValidator;
  delete numbersFilter;
}

int StringCalculator::add(const std::string & numbersSequence) const {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) const {
  int res = 0;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    res += numbers[i];
  }
  return res;
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) const {
  std::vector<int> numbers = this->numberExtractor->extractFrom(numbersSequence);
  numbersValidator->validate(numbers);
  return numbersFilter->ignoreTooBig(numbers);
}