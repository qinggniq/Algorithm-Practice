class Solution {
 public:
  vector<int> drawLine(vector<int>& screen, int width, int x1, int x2, int y) {
    unsigned int start_offset = x1 % 32;
    int first_full_byte = x1 / 32;
    if (start_offset != 0) {
      first_full_byte++;
    }
    unsigned int end_offset = x2 % 32;
    int last_full_byte = x2 / 32;
    if (end_offset != 31) {
      last_full_byte--;
    }

    //中间完整字节直接填充0xFF
    for (int i = first_full_byte; i <= last_full_byte; i++) {
      screen[(width / 32) * y + i] = 0xFFFFFFFF;
    }

    //构造开始和结束的掩码
    unsigned int start_mask = ((unsigned int)0xFFFFFFFF >> start_offset);
    unsigned int end_mask;
    if (end_offset == 31) {
      end_mask = ~((unsigned int)0xFFFFFFFF >> 32);
    } else {
      end_mask = ~((unsigned int)0xFFFFFFFF >>
                   (unsigned int)(end_offset + (unsigned int)1));
    }
    //设定直线起点和终点
    if ((x1 / 32) == (x2 / 32)) {  // x1 和 x2 在同一字节中

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
