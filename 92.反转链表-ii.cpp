/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.51%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 88.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode temp(0);
        temp.next = head;
        head = &temp;
        ListNode *p = head;
        while(m>1){
            p = p->next;
            m--;
            n--;
        }
        ListNode *start_prev = p;
        ListNode *start = p->next;
        ListNode *pre = p->next;
        p = p->next->next;
        n--;
        while(n>0){
            ListNode *temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            n--;
        }
        start_prev->next = pre;
        start->next = p;
        return head->next;
    }
};
// @lc code=end

