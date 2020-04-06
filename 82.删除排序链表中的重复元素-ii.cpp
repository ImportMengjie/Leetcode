/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (47.01%)
 * Likes:    249
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 85.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
        ListNode temp(0);
        temp.next = head;
        ListNode *head_head = &temp;
        ListNode *pre = head_head;
        ListNode *cur = head_head;
        bool delete_flag = false;
        while (cur->next)
        {
            cur = cur->next;
            if(cur!=pre->next){
                if(pre->next->val!=cur->val){
                    delete_flag = false;
                    if(pre->next->next!=cur){
                        pre->next = cur;
                    }
                    else
                        pre = pre->next;
                }else
                    delete_flag = true;
            }
        }
        if(pre->next!=NULL)
            pre->next->next = NULL;
        if(delete_flag)
            pre->next = NULL;
        return head_head->next;
    }
};
// @lc code=end

