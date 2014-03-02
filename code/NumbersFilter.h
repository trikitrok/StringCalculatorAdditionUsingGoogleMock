#pragma once

#include <vector>

class NumbersFilter
{
public:
  NumbersFilter();
  virtual ~NumbersFilter();

  std::vector<int> filter(const std::vector<int> & numbers) const;

private:
  std::vector<int> ignoreTooBig(const std::vector<int> & numbers) const;
};

