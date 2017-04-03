#ifndef TASTYLIB_LCS_H_
#define TASTYLIB_LCS_H_

#include "tastylib/internal/base.h"
#include <string>
#include <vector>
#include <algorithm>

TASTYLIB_NS_BEGIN

/*
Return the length of the longest common subsequence of two subsequences.

@param s1 The first subsequence
@param s2 The second subsequence
*/
inline std::size_t lcs(const std::string &s1, const std::string &s2) {
    if (s1.empty() || s2.empty()) {
        return 0;
    }
    // len[i][j] denotes the length of the longest common
    // subsequence of s1.substring(0, i + 1) and s2.substring(0, j + 1).
    std::vector<std::vector<std::size_t>> len(s1.size() + 1, std::vector<std::size_t>(s2.size() + 1, 0));
    for (std::size_t i = 1; i <= s1.size(); ++i) {
        for (std::size_t j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                len[i][j] = len[i - 1][j - 1] + 1;
            } else {
                len[i][j] = std::max(len[i][j - 1], len[i - 1][j]);
            }
        }
    }
    return len[s1.size()][s2.size()];
}

TASTYLIB_NS_END

#endif
