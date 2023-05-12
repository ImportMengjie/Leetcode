/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */


//Definition for singly-linked list.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        while(right) {
            if(right->val!=left->val) {
                left->next = right;
                left = left->next;
            }
            right = right->next;
        }
        left->next = nullptr;
        return head;
    }
};
// @lc code=end

