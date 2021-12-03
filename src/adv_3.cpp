#include "adv_3.h"

void advent_of_code_3_part1()
{
  std::vector<std::string> data{loadStringsToVector("../data/adv_3.txt")};
  const size_t bits{data[0].size()};
  int32_t gamma{0};
  int32_t epsilon{0};
  for (size_t i{0}; i < bits; ++i)
  {
    size_t count{0};
    for (size_t j{0}; j < data.size(); ++j)
      if (data[j][i] == '1')
        ++count;
    count >= data.size() / 2.0f ? gamma += 1 << (bits - 1 - i)
                                : epsilon += 1 << (bits - 1 - i);
  }
  std::cout << "Gamma: " << gamma << std::endl;
  std::cout << "Epsilon : " << epsilon << std::endl;
  std::cout << "Power Consumption : " << gamma * epsilon << std::endl;
}
