/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.74%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    32.1K
 * Total Submissions: 56.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *min_p= NULL;
        ListNode *min_head = NULL;
        ListNode *max_p = NULL;
        ListNode *max_head = NULL;
        while(head){
            ListNode *p = head;
            head = head->next;
            if(p->val>=x){
                if(max_p)
                    max_p->next = p;
                else
                    max_head = p;
                max_p = p;
            }
            else{
                if(min_p)
                    min_p->next = p;
                else
                    min_head = p;
                min_p= p;
            }
        }
        if(min_p)
            min_p->next = max_head;
        if(max_p)
            max_p->next = NULL;
        return min_head?min_head:max_head;
    }
};
// @lc code=end

