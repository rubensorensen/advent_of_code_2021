#include "adv_6.h"

void loadData(std::vector<int32_t>& fish, const char* filepath)
{
    std::fstream file;
    std::string line;
    file.open(filepath);
    getline(file, line);
    std::stringstream ss(line);
    while (getline(ss, line, ','))
        fish.push_back(std::stoi(line));
    file.close();
}

void advent_of_code_6_part1()
{
    std::vector<int32_t> fish;
    loadData(fish, "../data/adv_6.txt");
    for (size_t i{0}; i < 80; ++i)
    {
        int32_t newCount{0};
        for (auto& f : fish)
        {
            if (f == 0)
            {
                ++newCount;
                f = 7;
            }
            --f;
        }
        for (size_t j{0}; j < newCount; ++j)
            fish.push_back(8);
    }
    std::cout << "Amount of fish: " << fish.size() << std::endl;
}

void advent_of_code_6_part2() {}
