#include "adv_5.h"
#include "helper_functions.h"

std::pair<int32_t, int32_t> getPos(std::string pos)
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
    return std::make_pair(std::stoi(x), std::stoi(y));
}

std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>> getLine(std::string line)
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

std::vector<std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>> loadData(const char* filepath)
{
    std::vector<std::string> data{loadStringsToVector(filepath)};
    std::vector<std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>> lines;
    for (auto& d : data)
        lines.push_back(getLine(d));
    return lines;
}

void evaluateLargestValues(std::vector<std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>>& data, int32_t& x, int32_t& y)
{
    for (auto& p : data)
    {
        x = {std::max(x, std::max(p.first.first, p.second.first))};
        y = {std::max(y, std::max(p.first.second, p.second.second))};
    }
}

void advent_of_code_5_part1()
{
    auto data{loadData("../data/adv_5.txt")};

    int32_t largestX{0};
    int32_t largestY{0};
    evaluateLargestValues(data, largestX, largestY);

    // Allocate grid arrays for storing amount of intersections at any point
    int32_t** grid{new int32_t*[largestX + 1]};
    for (size_t i{0}; i <= largestX; ++i)
        grid[i] = new int32_t[largestY + 1];
    for (size_t i{0}; i <= largestX; ++i)
        for (size_t j{0}; j <= largestY; ++j)
            grid[i][j] = {0};

    // Increase amount of intersections at line points
    for (auto& p : data)
        if (p.first.first == p.second.first || p.first.second == p.second.second)
            for (int32_t i{std::min(p.first.first, p.second.first)}; i <= std::max(p.first.first, p.second.first); ++i)
                for (int32_t j{std::min(p.first.second, p.second.second)}; j <= std::max(p.first.second, p.second.second); ++j)
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

void advent_of_code_5_part2()
{
    auto data{loadData("../data/adv_5.txt")};

    int32_t largestX{0};
    int32_t largestY{0};
    evaluateLargestValues(data, largestX, largestY);

    // Allocate grid arrays for storing amount of intersections at any point
    int32_t** grid{new int32_t*[largestX + 1]};
    for (size_t i{0}; i <= largestX; ++i)
        grid[i] = new int32_t[largestY + 1];
    for (size_t i{0}; i <= largestX; ++i)
        for (size_t j{0}; j <= largestY; ++j)
            grid[i][j] = {0};

    // Increase amount of intersections at line points
    for (auto& p : data)
    {
        int32_t i{p.first.first};
        int32_t j{p.first.second};
        while (i != p.second.first || j != p.second.second)
        {
            grid[i][j] += 1;
            i += i == p.second.first ? 0 : i < p.second.first ? 1
                                                              : -1;
            j += j == p.second.second ? 0 : j < p.second.second ? 1
                                                                : -1;
        }
        grid[p.second.first][p.second.second] += 1;
    }

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
