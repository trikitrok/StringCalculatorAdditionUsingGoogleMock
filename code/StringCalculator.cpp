#include "StringCalculator.h"

#include "NumbersExtractor.h"
#include "NumbersValidator.h"

StringCalculator::StringCalculator(NumbersExtractor * numberExtractor,
  NumbersValidator * numbersValidator) {
  this->numberExtractor = numberExtractor;
  this->numbersValidator = numbersValidator;
}

StringCalculator::~StringCalculator() {
  delete numberExtractor;
  delete numbersValidator;
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
  std::vector<int> numbers = this->numberExtractor->extractNumbers(numbersSequence);
  numbersValidator->validate(numbers);
  return ignoreTooBig(numbers);
}

std::vector<int> StringCalculator::ignoreTooBig(const std::vector<int> & numbers) const {
  std::vector<int> filteredNumbers;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (notTooBig(numbers[i])) {
      filteredNumbers.push_back(numbers[i]);
    }
  }
  return filteredNumbers;
}

bool StringCalculator::notTooBig(int number) const {
  return !(number > 1000);
}