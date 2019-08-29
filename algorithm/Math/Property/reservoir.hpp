/*
 * The implemenation of Reservoir Sampling Algorithm by Knuth
 * author : qinggniq
 * github : https://github.com/qinggniq
 * Related:
 *      wiki: https://en.wikipedia.org/wiki/Reservoir_sampling
 *      intro:
 * https://github.com/linghuazaii/blog/wiki/%5BAlgorithm%5D%E7%99%BE%E5%BA%A6%EF%BC%9A%E8%93%84%E6%B0%B4%E6%B1%A0%E6%8A%BD%E6%A0%B7
 */

#pragma once
#include <random>
#include <vector>

using std::vector;

class Reservoir {
 public:
  Reservoir() = default;

  int choice(const vector<int>& v) const {
    if (v.empty()) return -1;
    std::random_device dev;
    std::mt19937 rng(dev());
    int ans = v[0];
    for (int i = 1; i < v.size(); ++i) {
      std::uniform_int_distribution<std::mt19937::result_type> dist6(0, i);
      if (dist6(rng) == 0) {
        ans = v[i];
      }
    }
    return ans;
  }
  vector<int> choiceK(const vector<int>& v, int K) const {
    if (v.empty() || K <= 0) return vector<int>();

    std::random_device dev;
    std::mt19937 rng(dev());
    vector<int> ans;
    for (int i = 0; i < K; ++i) ans.push_back(v[i]);
    for (int i = K; i < v.size(); ++i) {
      std::uniform_int_distribution<std::mt19937::result_type> dist6(0, i);
      int randnum = dist6(rng);
      if (randnum < K) {
        ans[randnum] = v[i];
      }
    }
    return ans;
  }
};