#include "adv_6.h"

class Lanternfish
{
public:
    Lanternfish(int32_t timer) : m_Timer(timer) {}
    ~Lanternfish() = default;

    inline int32_t Timer() { return m_Timer; }
    bool Age()
    {
        if (m_Timer == 0)
        {
            m_Timer = 6;
            return true;
        }
        --m_Timer;
        return false;
    }

private:
    int32_t m_Timer;
};

void loadData(std::vector<Lanternfish>& fish, const char* filepath)
{
    std::fstream file;
    std::string line;
    file.open(filepath);
    getline(file, line);
    std::stringstream ss(line);
    while (getline(ss, line, ','))
        fish.push_back(Lanternfish(std::stoi(line)));
    file.close();
}

void advent_of_code_6_part1()
{
    std::vector<Lanternfish> fish;
    loadData(fish, "../data/adv_6.txt");
    for (size_t i{0}; i < 80; ++i)
    {
        int32_t newCount{0};
        for (auto& f : fish)
            if (f.Age())
                ++newCount;
        for (size_t j{0}; j < newCount; ++j)
            fish.push_back(Lanternfish(8));
    }
    std::cout << "Amount of fish: " << fish.size() << std::endl;
}

void advent_of_code_6_part2() {}
