/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (78.92%)
 * Likes:    637
 * Dislikes: 0
 * Total Accepted:    587.2K
 * Total Submissions: 743.9K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 * 
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 * 
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size() - 1;
        int left = 0;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
};
// @lc code=end

