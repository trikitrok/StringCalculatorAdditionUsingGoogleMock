#include <gmock\gmock.h>

#include "..\code\DelimitersExtractor.h"

using namespace ::testing;

class ADelimitersExtractor : public Test {
public:
  const std::string DefaultDelimiters{",\n"};
  ADelimitersExtractor() : delimitersExtractor(DefaultDelimiters) {}
  ~ADelimitersExtractor() {}

  DelimitersExtractor delimitersExtractor;
};


TEST_F(ADelimitersExtractor, ExtractsDefaultDelimiters) {
  ASSERT_THAT(delimitersExtractor.extractDelimiters("3, 4, 6"), 
    Eq(DefaultDelimiters));
}


TEST_F(ADelimitersExtractor, ExtractsDefaultAndAdditionalOneCharacterDelimiter) {
  ASSERT_THAT(delimitersExtractor.extractDelimiters("//[@]\n1@2"), 
    Eq(DefaultDelimiters + "@"));
}
