#include <gmock\gmock.h>

#include "..\code\NumbersExtractor.h"
#include "..\code\DelimitersExtractor.h"

using namespace ::testing;

class ANumbersExtractor : public Test {
public:
  NumbersExtractor * numbersExtractor;

  void SetUp() {
    std::vector<std::string> DefaultDelimiters = {",", "\n"};
    numbersExtractor = new NumbersExtractor(new DelimitersExtractor(DefaultDelimiters));
  }

  void TearDown() {
    delete numbersExtractor;
  }
};

TEST_F(ANumbersExtractor, ReturnsEmptyListWhenItReceivesAnEmptySequence) {
  std::vector<int> numbers = numbersExtractor->extractFrom("");
  ASSERT_THAT(numbers, IsEmpty());
}

TEST_F(ANumbersExtractor, ReturnsTheOnlyNumberInSequence) {
  ASSERT_THAT(numbersExtractor->extractFrom("5"), ElementsAre(5));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByCommas) {
  ASSERT_THAT(numbersExtractor->extractFrom("3, 4, 6"), ElementsAre(3, 4, 6));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByCommasOrNewLineCharacters) {
  ASSERT_THAT(numbersExtractor->extractFrom("1\n2, 3"), ElementsAre(1, 2, 3));
}

TEST_F(ANumbersExtractor, ExtractsNumbersSeparatedByAdditionalDelimiters) {
  ASSERT_THAT(numbersExtractor->extractFrom("//[;]\n1;2"), ElementsAre(1, 2));
  ASSERT_THAT(numbersExtractor->extractFrom("//[@]\n1@2"), ElementsAre(1, 2));
}
