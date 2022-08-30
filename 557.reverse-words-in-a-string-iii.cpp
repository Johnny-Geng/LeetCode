/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.19%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    257.6K
 * Total Submissions: 347.2K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 * 
 * 
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 * 
 * 
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int left = -1;
        int right = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (left == -1) {
                left = i;
                continue;
            }

            if (s[i] == ' ' || i == s.size() - 1) {
                if (i != s.size() - 1) {
                    right = i - 1;
                }
                else { // last character in last word
                    right = i;
                }

                while (left < right) {
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    ++left;
                    --right;
                }
                left = -1;
            }
        }
        return s;
    }
};
// @lc code=end

