#include <gmock\gmock.h>

#include <vector>
#include "../code/StringUtils.h"

using namespace ::testing;

TEST(StringUtils, CanEscapeOneDelimeter) {
  ASSERT_THAT(StringUtils::escape("*"), Eq("\\*"));
  ASSERT_THAT(StringUtils::escape("\\"), Eq("\\\\"));
  ASSERT_THAT(StringUtils::escape("||"), Eq("\\|\\|"));
  ASSERT_THAT(StringUtils::escape(","), Eq(","));
}

TEST(StringUtils, CanEscapeSeveralDelimitersEvenThoseUsedInRegularExpressions) {

  std::vector<std::string> delimiters = {",", "*", "||", ";", "\\"};

  ASSERT_THAT(StringUtils::escapeDelimiters(delimiters),
    ElementsAre(",", "\\*", "\\|\\|", ";", "\\\\"));
}

TEST(StringUtils, CanSplitUsingMultipleTokens) {

  std::vector<std::string> delimiters = {",", "*", "??"};

  ASSERT_THAT(StringUtils::split("1*2??3,4", delimiters),
    ElementsAre("1", "2", "3", "4"));
}

TEST(StringUtils, CanTellIfAGivenStringRepresentsAnInteger) {
  ASSERT_TRUE(StringUtils::isAnInteger("1"));
  ASSERT_FALSE(StringUtils::isAnInteger("15 7 8"));
  ASSERT_FALSE(StringUtils::isAnInteger("1.5"));
  ASSERT_FALSE(StringUtils::isAnInteger("!15"));
}

TEST(StringUtils, CanJoinAVectorOfStrings) {
  ASSERT_THAT(StringUtils::join({"1", "2", "3"}, "|"), Eq("1|2|3"));
  ASSERT_THAT(StringUtils::join({"1", "2", "3"}, " "), Eq("1 2 3"));
  ASSERT_THAT(StringUtils::join({"1", "2", "3"}, ", "), Eq("1, 2, 3"));
  ASSERT_THAT(StringUtils::join({"1", "2", "3"}, ""), Eq("123"));
}
