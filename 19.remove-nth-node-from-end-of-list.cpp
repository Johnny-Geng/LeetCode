/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (44.44%)
 * Likes:    2155
 * Dislikes: 0
 * Total Accepted:    873.9K
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * Follow up: Could you do this in one pass?
 * 
 */

// @lc code=start

 // Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    // // method 1: recursion
    // int cur = 0;
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (!head) return NULL;
    //     head->next = removeNthFromEnd(head->next, n);
    //     ++cur;
    //     if (cur == n) {
    //         return head->next;
    //     }
    //     return head;
    // }

    // method 2: fast-slow pointers
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // to include the situation when head is deleted
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

