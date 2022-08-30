/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    1548
 * Dislikes: 0
 * Total Accepted:    536.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Try to come up with as many solutions as you can. There are at least three
 * different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        // // Method 1: Time O(N) Space O(N)
        // int n = nums.size();
        // vector<int> newArr(n);
        // for (int i = 0; i < n; ++i) {
        //     newArr[(i + k) % n] = nums[i];
        // }
        // nums.assign(newArr.begin(), newArr.end());

        // Method 2: Time O(N) Space O(1)
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size() - 1);
        
    }

};
// @lc code=end

