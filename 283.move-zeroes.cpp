/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (64.04%)
 * Likes:    1673
 * Dislikes: 0
 * Total Accepted:    821K
 * Total Submissions: 1.3M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you minimize the total number of operations done?
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                if (left != right) {
                    // swap
                    nums[left] = nums[right];
                    nums[right] = 0;   
                }
                ++left;
            }
            ++right;
        }
        // when swap, the left pointer will only stay at zero; to the left of the left pointer are all nums in order w/o zero
        // the right pointer will only swap with left when it finds a non-zero number && not pointing the same num as left
    }
};
// @lc code=end

