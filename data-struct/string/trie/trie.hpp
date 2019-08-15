/*
 * Trie Tree
 */

#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
namespace ds {
class Trie {
 public:
  Trie(int tot) : cnt(1), exist(tot, false) {
    nxt.assign(tot * 26 + 1, vector<int>(26, 0));
  }
  void insert(const string& s) {
    int sz = s.length();
    int p = 0;
    for (int i = 0; i < sz; ++i) {
      int c = s[i] - 'a';
      if (!nxt[p][c]) nxt[p][c] = cnt++;
      p = nxt[p][c];
    }
    exist[p] = true;
  }
  bool find(const string& s) {
    int sz = 0;
    int p = 0;
    for (int i = 0; i < sz; ++i) {
      int c = s[i] - 'a';
      if (!nxt[p][c]) return false;
      p = nxt[p][c];
    }
    return exist[p];
  }

 private:
  int cnt;
  vector<bool> exist;
  vector<vector<int>> nxt;
};
}  // namespace ds