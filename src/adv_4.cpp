#include "adv_4.h"

class Board
{
public:
    Board() = default;
    void AddRow(std::vector<int32_t> row)
    {
        std::vector<std::pair<int32_t, bool>> vec;
        for (auto num : row)
            vec.push_back(std::make_pair(num, false));
        m_Rows.push_back(vec);
    }

    void CheckNumber(int32_t number)
    {
        for (size_t i{0}; i < m_Rows.size(); ++i)
            for (size_t j{0}; j < m_Rows[i].size(); ++j)
                if (m_Rows[i][j].first == number)
                    m_Rows[i][j].second = true;
    }

    bool HasBingo()
    {
        for (size_t i{0}; i < m_Rows.size(); ++i)
        {
            bool bingoRow{true};
            bool bingoColumn{true};
            for (size_t j{0}; j < m_Rows[i].size(); ++j)
            {
                if (!m_Rows[i][j].second)
                    bingoRow = {false};
                if (!m_Rows[j][i].second)
                    bingoColumn = {false};
            }
            if (bingoRow || bingoColumn)
                return true;
        }
        return false;
    }

    int32_t Score(int32_t lastNum)
    {
        int32_t sum{0};
        for (auto& r : m_Rows)
            for (auto& n : r)
                if (!n.second)
                    sum += n.first;
        return sum * lastNum;
    }

    void Show()
    {
        for (auto r : m_Rows)
            for (auto n : r)
                std::cout << n.first << " ";
        std::cout << std::endl;
    }

private:
    std::vector<std::vector<std::pair<int32_t, bool>>> m_Rows;
};

void loadData(std::string filepath, std::vector<int32_t>& draws,
              std::vector<Board>& boards)
{
    std::string line;
    std::fstream file;
    std::stringstream ss;
    file.open(filepath);

    getline(file, line);
    ss << line;
    while (getline(ss, line, ','))
        draws.push_back(std::stoi(line));

    while (getline(file, line))
    {
        std::vector<int32_t> row;
        if (line.size() == 0)
            boards.push_back(Board());
        else
        {
            int32_t num;
            ss = {std::stringstream(line)};
            while (ss >> num)
                row.push_back(num);
            boards[boards.size() - 1].AddRow(row);
        }
    }
}

void advent_of_code_4_part1()
{
    std::vector<int32_t> draws;
    std::vector<Board> boards;
    loadData("../data/adv_4.txt", draws, boards);
    for (auto& draw : draws)
        for (auto& board : boards)
        {
            board.CheckNumber(draw);
            if (board.HasBingo())
            {
                std::cout << "Score: " << board.Score(draw) << std::endl;
                return;
            }
        }
}

void advent_of_code_4_part2()
{
    std::vector<int32_t> draws;
    std::vector<Board> boards;
    loadData("../data/adv_4.txt", draws, boards);
    size_t drawIndex{0};
    while (drawIndex < draws.size() && boards.size() > 1)
    {
        auto iter{boards.begin()};
        while (iter != boards.end())
        {
            iter->CheckNumber(draws[drawIndex]);
            if (iter->HasBingo())
                boards.erase(iter);
            else
                ++iter;
        }
        ++drawIndex;
    }
    while (drawIndex < draws.size())
    {
        auto board{boards[0]};
        board.CheckNumber(draws[drawIndex]);
        if (board.HasBingo())
        {
            std::cout << "Score: " << board.Score(draws[drawIndex]);
            return;
        }
        ++drawIndex;
    }
}
