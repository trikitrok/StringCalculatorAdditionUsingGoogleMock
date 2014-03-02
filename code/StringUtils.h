#pragma once

#include <string>
#include <vector>

namespace StringUtils
{
  std::vector<std::string> split(const std::string & str,
    const std::vector<std::string> & delimiters);
  
  std::string scape(char delimiter);
  
  std::string scape(const std::string & delimiter);
  
  std::vector<std::string> scapeDelimiters(
    const std::vector<std::string> & delimiters);

  bool isAnInteger(const std::string & token);

  std::string extractRegion(const std::string & str,
    int from, int to);
};


