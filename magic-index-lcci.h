// https://leetcode-cn.com/problems/magic-index-lcci/

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMagicIndex(const vector<int> &numbers) {
        for (int l = 0, r = numbers.size() - 1; l < r;) {
            int m = (l + r) >> 1;
            if (numbers[m] == m)
                return m;
            if (numbers[m] > m)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }

    template <char F> void fn();

  private:
    int v_ = 1;
};

template <> inline void Solution::fn<'0'>() { cout << "0" << v_ << endl; }

inline void test() {
    Solution solution;
    solution.fn<'0'>();
    // cout << solution.findMagicIndex({0, 2, 3, 4, 5}) << endl; // 0
    // cout << solution.findMagicIndex({1, 1, 1}) << endl;       // 1
    // cout << solution.findMagicIndex({-1, 2, 3}) << endl; // 0
}