#include <gmock\gmock.h>

#include "..\code\StringCalculator.h"

using namespace ::testing;

TEST(StringCalculatorAddition, ReturnsZeroWhenItReceivesAnEmptySequence) {
  StringCalculator stringCalculator;

  ASSERT_THAT(stringCalculator.add(""), Eq(0));
}

TEST(StringCalculatorAddition, ReturnsOnlyNumberInSequence) {
  StringCalculator stringCalculator;

  ASSERT_THAT(stringCalculator.add("5"), Eq(5));
}