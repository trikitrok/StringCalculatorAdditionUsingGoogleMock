#include <gmock\gmock.h>

#include "..\code\NumbersExtractor.h"

using namespace ::testing;

class ANumbersExtractor : public Test {
public:
  NumbersExtractor numbersExtractor;
};


TEST_F(ANumbersExtractor, ReturnsEmptyListWhenItReceivesAnEmptySequence) {
  std::vector<int> numbers = numbersExtractor.extractFrom("");
  ASSERT_THAT(numbers, IsEmpty());
}

TEST_F(ANumbersExtractor, ReturnsTheOnlyNumberInSequence) {
  ASSERT_THAT(numbersExtractor.extractFrom("5"), ElementsAre(5));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByCommas) {
  ASSERT_THAT(numbersExtractor.extractFrom("3, 4, 6"), ElementsAre(3, 4, 6));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByCommasOrNewLineCharacters) {
  ASSERT_THAT(numbersExtractor.extractFrom("1\n2, 3"), ElementsAre(1, 2, 3));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByAdditionalDelimiters) {
  ASSERT_THAT(numbersExtractor.extractFrom("//[;]\n1;2"), ElementsAre(1, 2));
  ASSERT_THAT(numbersExtractor.extractFrom("//[@]\n1@2"), ElementsAre(1, 2));
}
