#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>
#include <unordered_map>

class Board {
 public:
  void Add(int);
  void Mark(int);
  bool IsDone() const { return is_done_; };
  int RSum() const;
  friend std::ostream& operator<<(std::ostream&, const Board*);
 private:
  const int kSize = 5;
  int cnt_ = 0;
  bool is_done_ = false;
  std::vector<std::vector<int>> board_;
  std::vector<int> line_;
  std::unordered_map<int, std::vector<int>> loc_;
};

std::ostream& operator<<(std::ostream& os, const Board* board) {
  for (const auto& line: board->board_) {
    for (const auto& val: line) {
      os << std::setfill(' ') << std::setw(3) << val;
    }
    os << '\n';
  }
  return os;
}

void Board::Add(int val) {
  line_.push_back(val);
  loc_[val].push_back(cnt_);
  if (line_.size() == kSize) {
    board_.push_back(line_);
    line_.clear();
  }
  cnt_++;
}

void Board::Mark(int val) {
  auto it = loc_.find(val);
  if (it == loc_.end()) {
    return;
  }

  for (auto loc: it->second) {
    const int x = loc/kSize;
    const int y = loc%kSize;
    board_[x][y] = -board_[x][y]-1;
    bool done = true;
    for (int i = 0; done && i < kSize; i++) {
      if (board_[i][y] >= 0) {
        done = false;
      }
    }
    if (done) {
      is_done_ = true;
    }
    done = true;
    for (int i = 0; done && i < kSize; i++) {
      if (board_[x][i] >= 0) {
        done = false;
      }
    }
    if (done) {
      is_done_ = true;
    }
  }
}

int Board::RSum() const {
  int sum = 0;
  for (auto const& line: board_) {
    for (auto val: line) {
      if (val > 0) {
        sum += val;
      }
    }
  }
  return sum;
}

int main() {
  using std::vector;

  std::string randoms;
  std::cin >> randoms;

  std::istringstream ss(randoms);

  vector<int> nums;
  while (ss) {
    char c;
    int num;
    ss >> num >> c;
    nums.push_back(num);
  }
  std::cout << "nums:" << nums.size() << "\n";

  std::unordered_map<int, vector<int>> v_map;
  vector<std::unique_ptr<Board>> boards;
  int cnt = 0;
  int num = 0;
  while (std::cin >> num) {
    auto board = std::make_unique<Board>();
    board->Add(num);
    v_map[num].push_back(cnt);
    for (int i = 0; i < 24; i++) {
      std::cin >> num;
      v_map[num].push_back(cnt);
      board->Add(num);
    }
    boards.push_back(std::move(board));
    cnt++;
  }

  int last;
  for (auto val: nums) {
    //std::cout << "marking " << val << '\n';
    auto it = v_map.find(val);
    if (it == v_map.end()) {
      continue;
    }
    for (auto id: it->second) {
      if (boards[id]->IsDone()) {
        continue;
      }
      boards[id]->Mark(val);
      if (boards[id]->IsDone()) {
        std::cout << boards[id]->RSum() << ' ' << val << '\n';
        last = boards[id]->RSum() * val;
      }
    }
  }
  std::cout << last << "\n";
}
