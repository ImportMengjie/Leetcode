/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.29%)
 * Likes:    958
 * Dislikes: 0
 * Total Accepted:    235.6K
 * Total Submissions: 341.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */
#define NULL 0

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head){
            ListNode* prev = head;
            ListNode* cur = head->next;
            prev->next = NULL;
            while(cur){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            return prev;
        }
        return head;
    }
};
// @lc code=end

