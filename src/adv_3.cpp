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

int32_t filter(std::vector<std::string> data, const bool bitCriteria)
{
    const size_t bits{data[0].size()};
    for (size_t i{0}; i < bits; ++i)
    {
        if (data.size() == 1) // Base case: Return remaining value
            break;
        size_t count{0};
        for (size_t j{0}; j < data.size(); ++j)
            if (data[j][i] == '1')
                ++count;
        char targetBit;
        if (bitCriteria)
            targetBit = {count >= data.size() / 2.0f ? '1' : '0'};
        else
            targetBit = {count < data.size() / 2.0f ? '1' : '0'};

        auto iter{data.begin()};
        while (iter != data.end())
        {
            if ((*iter)[i] == targetBit)
                ++iter;
            else
                data.erase(iter);
        }
    }
    if (data.size() == 1)
    {
        int32_t returnValue{0};
        for (size_t j{0}; j < bits; ++j)
            returnValue += (data[0][j] == '1') ? 1 << (bits - 1 - j) : 0;
        return returnValue;
    }
    return -1;
}

void advent_of_code_3_part2()
{
    std::vector<std::string> data{loadStringsToVector("../data/adv_3.txt")};
    int32_t o2GenRating{filter(data, 1)};
    int32_t co2ScrubberRating{filter(data, 0)};
    std::cout << "Oxygen generator rating: " << o2GenRating << std::endl;
    std::cout << "CO2 scrubber rating: " << co2ScrubberRating << std::endl;
    std::cout << "Life support rating: " << o2GenRating * co2ScrubberRating
              << std::endl;
}
