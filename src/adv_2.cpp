#include "adv_1.h"

void advent_of_code_2_part1()
{
    std::vector<std::string> data{loadStringsToVector("../data/adv_2.txt")};
    int32_t position{0};
    int32_t depth{0};

    for (size_t i{0}; i < data.size(); ++i)
    {
        std::stringstream ss(data[i]);
        std::string str;
        std::vector<std::string> instruction;
        while (getline(ss, str, ' '))
            instruction.push_back(str);
        if (instruction[0] == "up")
            depth -= std::stoi(instruction[1]);
        if (instruction[0] == "down")
            depth += std::stoi(instruction[1]);
        else if (instruction[0] == "forward")
            position += std::stoi(instruction[1]);
    }

    std::cout << "Position: " << position << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    std::cout << "Multiplied together: " << position * depth << std::endl;
}

void advent_of_code_2_part2()
{
    std::vector<std::string> data{loadStringsToVector("../data/adv_2.txt")};
    int32_t position{0};
    int32_t depth{0};
    int32_t aim{0};

    for (size_t i{0}; i < data.size(); ++i)
    {
        std::stringstream ss(data[i]);
        std::string str;
        std::vector<std::string> instruction;
        while (getline(ss, str, ' '))
            instruction.push_back(str);
        if (instruction[0] == "up")
            aim -= std::stoi(instruction[1]);
        if (instruction[0] == "down")
            aim += std::stoi(instruction[1]);
        else if (instruction[0] == "forward")
        {
            position += std::stoi(instruction[1]);
            depth += aim * std::stoi(instruction[1]);
        }
    }

    std::cout << "Position: " << position << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    std::cout << "Multiplied together: " << position * depth << std::endl;
}
