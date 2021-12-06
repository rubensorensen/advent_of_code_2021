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
    {
      for (size_t j{0}; j < m_Rows[i].size(); ++j)
        if (m_Rows[i][j].first == number)
          m_Rows[i][j].second = true;
    }
  }

  bool HasBingo()
  {
    bool bingoRow{false};
    bool bingoColumn{false};
    for (size_t i{0}; i < m_Rows.size(); ++i)
    {
      bool bingo{true};
      for (size_t j{0}; j < m_Rows[i].size(); ++j)
        if (!m_Rows[i][j].second)
          bingo = {false};
      bingoRow |= bingo;
    }
    for (size_t i{0}; i < m_Rows[0].size(); ++i)
    {
      bool bingo{true};
      for (size_t j{0}; j < m_Rows.size(); j++)
        if (!m_Rows[j][i].second)
          bingo = {false};
      bingoColumn |= bingo;
    }
    return bingoRow || bingoColumn;
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

  private:
  std::vector<std::vector<std::pair<int32_t, bool>>> m_Rows;
};

std::vector<int32_t> lineToArray(std::string line, bool commaSeperated = false)
{
  std::vector<int32_t> vec;
  std::stringstream ss(line);
  if (commaSeperated)
    while (getline(ss, line, ','))
      vec.push_back(std::stoi(line));
  else
  {
    int32_t num;
    while (ss >> num)
      vec.push_back(num);
  }
  return vec;
}

void loadData(std::vector<int32_t>& draws, std::vector<Board>& boards)
{
  std::string line;
  std::fstream file;
  file.open("../data/adv_4.txt");

  getline(file, line);
  draws = {lineToArray(line, true)};

  while (getline(file, line))
  {
    if (line.size() == 0)
    {
      boards.push_back(Board());
      continue;
    }
    boards[boards.size() - 1].AddRow(lineToArray(line));
  }
  file.close();
}

void advent_of_code_4_part1()
{
  std::vector<int32_t> draws;
  std::vector<Board> boards;
  loadData(draws, boards);
  for (auto& draw : draws)
  {
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
}

void advent_of_code_4_part2()
{
  std::vector<int32_t> draws;
  std::vector<Board> boards;
  loadData(draws, boards);
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
