#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> drawLine(vector<int>& screen, int width, int x1, int x2, int y) {
    int start_offset = x1 % 32;
    int first_full_byte = x1 / 32;
    if (start_offset != 0) {
      first_full_byte++;
    }
    int end_offset = x2 % 32;
    int last_full_byte = x2 / 32;
    if (end_offset != 31) {
      last_full_byte--;
    }

    //中间完整字节直接填充0xFF
    for (int i = first_full_byte; i <= last_full_byte; i++) {
      screen[(width / 32) * y + i] = 0xFFFFFFFF;
    }

    //构造开始和结束的掩码
    int start_mask = (0xFFFFFFFF >> start_offset);
    int end_mask = ~(0xFFFFFFFF >> (end_offset + 1));
    cout << (x1 / 32) << " " << (x2 / 32) << endl;
    //设定直线起点和终点
    if ((x1 / 32) == (x2 / 32)) {  // x1 和 x2 在同一字节中
      cout << start_mask << " " << end_mask << " " << (start_mask & end_mask)
           << endl;
      screen[x1 / 32] = (start_mask & end_mask);
    } else {
      if (start_offset != 0) {
        int byte_num = (width / 32) * y + first_full_byte - 1;
        screen[byte_num] |= start_mask;
      }
      if (end_offset != 31) {
        int byte_num = (width / 32) * y + last_full_byte + 1;
        screen[byte_num] |= end_mask;
      }
    }
    return screen;
  }
};

int main() {
  Solution sol;
  vector<int> in(3, 0);
  auto res = sol.drawLine(in, 32, 30, 31, 0);
  for (int a : res) {
    cout << a << " ";
  }
  cout << endl;
}