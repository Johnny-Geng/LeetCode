/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.cn/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (22.22%)
 * Likes:    946
 * Dislikes: 0
 * Total Accepted:    175.9K
 * Total Submissions: 791.7K
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, 8.345 would be truncated to 8, and -2.7335
 * would be truncated to -2.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31
 * - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) 
            return INT_MIN;

        // record signs
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // change both to negative value to avoid overflow issue
        dividend = (dividend > 0)?(-dividend):dividend;
        divisor = (divisor > 0)?(-divisor):divisor;
        
        int quotient = 0;
        while (dividend <= divisor) {
            int largestDiv = divisor;
            int mul = 1;
            if (!(largestDiv < -(INT_MAX >> 1))) { // to avoid overflow: e.g. 1073741824 + 1073741824 > INT_MAX
                while (dividend <= (largestDiv + largestDiv)) {
                    largestDiv += largestDiv;
                    mul += mul;
                    // to avoid overflow: e.g. 1073741824 + 1073741824 > INT_MAX
                    if (largestDiv < -(INT_MAX >> 1)) {
                        break;
                    }
                }
            }
            dividend -= largestDiv;
            quotient += mul;
        }
        return negative?(-quotient):quotient;
    }
};
// @lc code=end

