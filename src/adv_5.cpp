#include "adv_5.h"
#include "helper_functions.h"

struct Pos
{
    int32_t x;
    int32_t y;
};

Pos getPos(std::string pos)
{
    std::string x{""};
    std::string y{""};
    size_t nextIdx{0};
    for (size_t i{nextIdx}; i < pos.size(); ++i)
    {
        if (pos[i] == ',')
        {
            nextIdx = {i + 1};
            break;
        }
        x.push_back(pos[i]);
    }
    for (size_t i{nextIdx}; i < pos.size(); ++i)
        y.push_back(pos[i]);
    return Pos{std::stoi(x), std::stoi(y)};
}

std::pair<Pos, Pos> getLine(std::string line)
{
    std::string pos1{""};
    std::string pos2{""};
    size_t nextIdx{0};
    for (size_t i{nextIdx}; i < line.size(); ++i)
    {
        if (line[i] == ' ')
        {
            nextIdx = {i + 4};
            break;
        }
        pos1.push_back(line[i]);
    }
    for (size_t i{nextIdx}; i < line.size(); ++i)
        pos2.push_back(line[i]);

    return std::make_pair(getPos(pos1), getPos(pos2));
}

std::vector<std::pair<Pos, Pos>> loadData(const char* filepath)
{
    std::vector<std::string> data{loadStringsToVector(filepath)};
    std::vector<std::pair<Pos, Pos>> lines;
    for (auto& d : data)
        lines.push_back(getLine(d));
    return lines;
}

void advent_of_code_5_part1()
{
    std::vector<std::pair<Pos, Pos>> data{loadData("../data/adv_5.txt")};

    // Remove any non-straight lines
    auto iter{data.begin()};
    while (iter != data.end())
        if (iter->first.x == iter->second.x || iter->first.y == iter->second.y)
            ++iter;
        else
            data.erase(iter);

    // Evaluate largest values
    int32_t largestX{0};
    int32_t largestY{0};
    for (auto& p : data)
    {
        largestX = {std::max(largestX, std::max(p.first.x, p.second.x))};
        largestY = {std::max(largestY, std::max(p.first.y, p.second.y))};
    }

    // Allocate grid arrays for storing amount of intersections at any point
    int32_t** grid{new int32_t*[largestX + 1]};
    for (size_t i{0}; i <= largestX; ++i)
        grid[i] = new int32_t[largestY + 1];
    for (size_t i{0}; i <= largestX; ++i)
        for (size_t j{0}; j <= largestY; ++j)
            grid[i][j] = {0};

    // Increase amount of intersections at line points
    for (auto& p : data)
        for (int32_t i{std::min(p.first.x, p.second.x)}; i <= std::max(p.first.x, p.second.x); ++i)
            for (int32_t j{std::min(p.first.y, p.second.y)}; j <= std::max(p.first.y, p.second.y); ++j)
                grid[i][j] += 1;

    // Get amount of points with two or more intersections
    int32_t result{0};
    for (size_t i{0}; i <= largestX; ++i)
        for (size_t j{0}; j <= largestY; ++j)
            if (grid[i][j] >= 2)
                ++result;
    std::cout << "Points with 2 or more overlaps: " << result << std::endl;

    for (size_t i{0}; i <= largestX; ++i)
        delete[] grid[i];
    delete[] grid;
}

void advent_of_code_5_part2() {}
