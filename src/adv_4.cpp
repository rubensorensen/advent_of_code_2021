#include "adv_4.h"

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

class Board
{
  public:
  Board() = default;
  void AddRow(std::vector<int32_t> row) { m_Rows.push_back(row); }
  void ShowBoard()
  {
    for (auto& r : m_Rows)
    {
      for (auto& n : r)
        std::cout << n << " ";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  private:
  std::vector<std::vector<int32_t>> m_Rows;
};

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

  std::cout << "Draws: " << std::endl;
  for (auto& d : draws)
    std::cout << d << " ";
  std::cout << '\n' << std::endl;
  std::cout << "Amount of boards: " << boards.size() << '\n' << std::endl;
  for (size_t i{0}; i < boards.size(); ++i)
  {
    std::cout << "Board " << i << ':' << std::endl;
    boards[i].ShowBoard();
  }
}

void advent_of_code_4_part2() {}
