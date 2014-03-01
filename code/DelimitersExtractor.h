#pragma once

#include <string>

class DelimitersExtractor
{
public:
  DelimitersExtractor(const std::string & defaultDelimiters);
  virtual ~DelimitersExtractor();

  std::string extractDelimiters(const std::string & numbersSequence) const;

private:
  std::string defaultDelimiters;

  std::string extractAdditionalDelimiter(const std::string & numbersSequence) const;
};

