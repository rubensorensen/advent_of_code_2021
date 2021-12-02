#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "pch.h"

std::vector<std::string> loadStringsToVector(const char* path)
{
  std::vector<std::string> data;
  std::string line;
  std::fstream file;
  file.open(path);
  while (getline(file, line))
    data.push_back(line);
  return data;
}

std::vector<int32_t> loadIntsToVector(const char* path)
{
  std::vector<int32_t> data;
  std::string line;
  std::fstream file;
  file.open(path);
  while (getline(file, line))
    data.push_back(std::stoi(line));
  return data;
}

#endif
