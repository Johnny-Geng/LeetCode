/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.72%)
 * Likes:    18542
 * Dislikes: 3781
 * Total Accepted:    2.8M
 * Total Submissions: 7.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        bool plusOne = false;
        while (true) {
            int num = 0;
            if (l1 != nullptr) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num += l2->val;
                l2 = l2->next;
            }

            if (plusOne) {
                num++;
            }
            if (num >= 10) {
                plusOne = true;
                num -= 10;
            }
            else {
                plusOne = false;
            }
            temp->val = num;
            // next
            if (!(l1 == nullptr && l2 == nullptr && plusOne == false)) {
                ListNode* next = new ListNode();
                temp->next = next;
                temp = next;
            }
            else {
                break;
            }
        }
        return head;
    }
};
// @lc code=end

