/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.94%)
 * Likes:    590
 * Dislikes: 0
 * Total Accepted:    375.4K
 * Total Submissions: 544.5K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * 
 * 
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // find the index of the biggest negative number
        int neg = -1, size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] < 0) {
                neg = i;
            }
            else {
                break;
            }
        }

        // comparing squared numbers and insert them into answer vector O(N)
        vector<int> answer;
        int i = neg, j = neg + 1;
        while (i >= 0 || j < size) {
            if (j == size) { // pos number finished neg number unfinished 
                answer.push_back(nums[i] * nums[i]);
                i--;
            }
            else if (i < 0) { // neg number finished pos number unfinished
                answer.push_back(nums[j] * nums[j]);
                j++;
            }
            else if (nums[i] * nums[i] < nums[j] * nums[j]) { // neg num < pos num
                answer.push_back(nums[i] * nums[i]);
                i--;
            }
            else { // neg num >= pos num
                answer.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return answer;
    }

};
// @lc code=end

