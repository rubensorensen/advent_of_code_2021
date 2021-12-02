#ifndef ADV_1_H
#define ADV_1_H

#include "helper_functions.h"
#include "pch.h"

void advent_of_code_1_part1()
{
  std::vector<int32_t> data{loadIntsToVector("../data/adv_1.txt")};
  int32_t increments{0};
  int32_t decrements{0};
  for (size_t i{1}; i < data.size(); ++i)
  {
    if (data[i] > data[i - 1])
      ++increments;
    else if (data[i] < data[i - 1])
      ++decrements;
  }
  std::cout << "Increments: " << increments << std::endl;
  std::cout << "Decrements: " << decrements << std::endl;
}

void advent_of_code_1_part2()
{
  std::vector<int32_t> data{loadIntsToVector("../data/adv_1.txt")};
  int32_t increments{0};
  int32_t decrements{0};
  for (size_t i{1}; i < data.size() - 2; ++i)
  {
    int32_t a{data[i - 1] + data[i - 0] + data[i + 1]};
    int32_t b{data[i + 0] + data[i + 1] + data[i + 2]};
    if (b > a)
      ++increments;
    else if (b < a)
      ++decrements;
  }
  std::cout << "Increments: " << increments << std::endl;
  std::cout << "Decrements: " << decrements << std::endl;
}

#endif
