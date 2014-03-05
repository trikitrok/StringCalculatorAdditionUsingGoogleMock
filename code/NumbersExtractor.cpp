#include "NumbersExtractor.h"

#include "NumbersSequenceTokenizer.h"
#include "NumbersValidator.h"
#include "NumbersFilter.h"

NumbersExtractor::NumbersExtractor(
  NumbersSequenceTokenizer * numbersSequenceTokenizer,
  NumbersValidator * numbersValidator,
  NumbersFilter * numbersFilter) {
  this->numbersSequenceTokenizer = numbersSequenceTokenizer;
  this->numbersValidator = numbersValidator;
  this->numbersFilter = numbersFilter;
}

NumbersExtractor::~NumbersExtractor() {
  delete numbersSequenceTokenizer;
  delete numbersValidator;
  delete numbersFilter;
}

std::vector<int> NumbersExtractor::extractNumbers(const std::string & numbersSequence) const {
  auto numbers = numbersSequenceTokenizer->extractFrom(numbersSequence);
  numbersValidator->validate(numbers);
  return numbersFilter->filter(numbers);
}


