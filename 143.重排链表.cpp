/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.35%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 41.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head&&head->next&&head->next->next){
            ListNode* fast=head, *slow = head;
            while (fast->next&&fast->next->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }

            ListNode* new_head = slow->next;
            slow->next = nullptr;
            if(new_head){
                ListNode* prev = new_head;
                ListNode* temp_head = new_head->next;
                prev->next = nullptr;
                while (temp_head)
                {
                    ListNode* t = temp_head->next;
                    temp_head->next = prev;
                    prev = temp_head;
                    if(t==nullptr)
                        new_head = temp_head;
                    temp_head = t;
                }
            }

            while (head&&new_head)
            {
                ListNode* t = head->next;
                head->next = new_head;
                head = new_head;
                new_head = t;
            }
        }
    }
};
// @lc code=end

