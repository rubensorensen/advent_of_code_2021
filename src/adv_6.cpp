#include "adv_6.h"

void loadData(const char* filepath, int64_t* table)
{
    std::fstream file;
    std::string line;
    file.open(filepath);
    getline(file, line);
    std::stringstream ss(line);
    while (getline(ss, line, ','))
        table[std::stoi(line)]++;
    file.close();
}

void simulateDay(int64_t* table)
{
    int64_t temp = table[0];
    for (size_t i = 0; i < 6; ++i)
        table[i] = table[i + 1];
    table[6] = temp + table[7];
    table[7] = table[8];
    table[8] = temp;
}

int64_t amountOfFish(int64_t* table)
{
    int64_t fish{0};
    for (size_t i{0}; i < 9; ++i)
        fish += table[i];
    return fish;
}

void advent_of_code_6_part1()
{
    int64_t table[9]{0};
    loadData("../data/adv_6.txt", table);
    for (size_t i{0}; i < 80; ++i)
        simulateDay(table);
    std::cout << "Fish: " << amountOfFish(table) << std::endl;
}

void advent_of_code_6_part2()
{
    int64_t table[9]{0};
    loadData("../data/adv_6.txt", table);
    for (size_t i{0}; i < 256; ++i)
        simulateDay(table);
    std::cout << "Fish: " << amountOfFish(table) << std::endl;
}
