/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.13%)
 * Likes:    740
 * Dislikes: 0
 * Total Accepted:    213.4K
 * Total Submissions: 483.7K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // edge case
        if (s1.size() > s2.size()) {
            return false;
        }

        
    }
};
// @lc code=end

