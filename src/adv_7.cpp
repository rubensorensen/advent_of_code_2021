#include "adv_7.h"

void loadData(const char* filepath, std::vector<int32_t>& vec)
{
    std::ifstream file;
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
    for (auto n{crabs.begin()}; n != crabs.end(); ++n)
        fuelCost += std::abs(*m - *n);
    std::cout << "Minimum fuel cost: " << fuelCost << std::endl;
}

void advent_of_code_7_part2()
{
    std::vector<int32_t> crabs;
    loadData("../data/adv_7.txt", crabs);

    int32_t fuelCost{0};
    int32_t avg{static_cast<int32_t>(std::accumulate(crabs.begin(), crabs.end(), 0) / crabs.size())};
    std::cout << avg << std::endl;
    for (auto n{crabs.begin()}; n != crabs.end(); ++n)
        for (size_t i{1}; i <= std::abs(*n - avg); ++i)
            fuelCost += i;
    std::cout << "Minimum fuel cost: " << fuelCost << std::endl;
}
