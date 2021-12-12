#include "adv_7.h"

void loadData(const char* filepath, std::vector<int32_t>& vec)
{
    std::fstream file;
    std::string line;
    file.open(filepath);
    getline(file, line);
    std::stringstream ss(line);
    while (getline(ss, line, ','))
        vec.push_back(std::stoi(line));
    file.close();
}

void advent_of_code_7_part1()
{
    std::vector<int32_t> crabs;
    loadData("../data/adv_7.txt", crabs);

    int32_t fuelCost{0};
    auto n{crabs.begin()};
    auto m{n + (crabs.size() / 2)};
    std::nth_element(n, m, crabs.end()); // Place median value at m
    while (n != crabs.end())
    {
        if (n == m)
            n++;
        fuelCost += std::abs(*m - *n++);
    }
    std::cout << "Minimum fuel cost: " << fuelCost << std::endl;
}

void advent_of_code_7_part2() {}
