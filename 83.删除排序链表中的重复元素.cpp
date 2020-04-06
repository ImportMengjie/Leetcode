/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.75%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    88.3K
 * Total Submissions: 177.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur)
        {
            if(pre->val!=cur->val){
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = NULL;
        return head;
        
    }
};
// @lc code=end

