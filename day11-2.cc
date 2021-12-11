#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

const int kThreshold = 9;
const int kRow = 10, kCol = 10;
const std::vector<std::pair<int, int>> kMove = {
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1}, {0, 1},
  {1, -1}, {1, 0}, {1, 1},
};

void TurnOn(std::array<std::array<int, kCol>, kRow>& grid,
            std::array<std::array<bool, kCol>, kRow>& on,
            int row, int col, int &flash) {

  flash++;
  on[row][col] = true;
  grid[row][col] = 0;

  for (const auto& move: kMove) {
    int row_nbr = row + move.first, col_nbr = col + move.second;

    if (row_nbr < 0 || row_nbr >= kRow ||
        col_nbr < 0 || col_nbr >= kCol ||
        on[row_nbr][col_nbr]) {
      continue;
    }

    if (++grid[row_nbr][col_nbr] > kThreshold) {
      TurnOn(grid, on, row_nbr, col_nbr, flash);
    }
  }
}

int main() {
  std::array<std::array<int, kCol>, kRow> grid;

  for (int row = 0; row < kRow; row++) {
    for (int col = 0; col < kCol; col++) {
      char val;
      std::cin >> val;
      grid[row][col] = val - '0';
    }
  }

  int flash = 0;

  int step = 0;
  while (true) {
    step++;
    std::array<std::array<bool, kCol>, kRow> on;
    std::for_each(on.begin(), on.end(), [](auto&row){ row.fill(false);});
    for (int row = 0; row < kRow; row++) {
      for (int col = 0; col < kCol; col++) {
        if (!on[row][col] && ++grid[row][col] > kThreshold) {
          TurnOn(grid, on, row, col, flash);
        }
      }
    }

    if (std::all_of(on.begin(), on.end(),
                    [](auto &row) {
                      return std::all_of(row.begin(), row.end(),
                                         [](bool on){ return on; });
                    })) {
      std::cout << "first sync: " << step << '\n';
      break;
    }

  }
}

