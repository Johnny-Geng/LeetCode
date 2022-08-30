/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.12%)
 * Likes:    23944
 * Dislikes: 1065
 * Total Accepted:    3.3M
 * Total Submissions: 10M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // sliding window questions
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int i = 0, j = 0, n = s.size(), ans = 0;
        while (i < n && j < n) {
            // no duplicates
            if (chars.find(s[j]) == chars.end()) {
                chars.insert(s[j++]);
                ans = max(ans, j-i);
            }
            // duplicates
            else {
                chars.erase(s[i++]);
            }
        }
        return ans;
    }
};
// @lc code=end

