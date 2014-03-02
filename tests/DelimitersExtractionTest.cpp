#include <gmock\gmock.h>

#include "..\code\DelimitersExtractor.h"

using namespace ::testing;



class ADelimitersExtractor : public Test {
public:
  DelimitersExtractor * delimitersExtractor;

  void SetUp() {
    std::vector<std::string> DefaultDelimiters = {",", "\n"};
    delimitersExtractor = new DelimitersExtractor(DefaultDelimiters);
  }

  void TearDown() {
    delete delimitersExtractor;
  }
};

TEST_F(ADelimitersExtractor, ExtractsDefaultDelimiters) {
  ASSERT_THAT(delimitersExtractor->extractDelimitersList("3, 4, 6"), 
    ElementsAre(",", "\n"));
}

TEST_F(ADelimitersExtractor, ExtractsDefaultAndAdditionalOneCharacterDelimiter) {
  ASSERT_THAT(delimitersExtractor->extractDelimitersList("//[@]\n1@2"),
    ElementsAre(",", "\n", "@"));
}

TEST_F(ADelimitersExtractor, ExtractsDefaultAndAdditionalDelimiterWithMoreThanOneCharacter) {
  ASSERT_THAT(delimitersExtractor->extractDelimitersList("//[@@]\n1@2"),
    ElementsAre(",", "\n", "@@"));
}

TEST_F(ADelimitersExtractor, ExtractsDefaultAndSeveralAdditionalDelimiters) {
  ASSERT_THAT(delimitersExtractor->extractDelimitersList("//[*][=>]\n1=>2*3"),
    ElementsAre(",", "\n", "*", "=>"));
}
