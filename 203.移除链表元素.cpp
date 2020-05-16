/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.83%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    77.2K
 * Total Submissions: 170.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode t(-1);
        t.next = head;
        head = &t;

        ListNode* p = head;
        while(p->next){
            if(p->next->val==val){
                ListNode* deleteNode = p->next;
                p->next = deleteNode->next;
                delete deleteNode;
            }else
                p = p->next;
        }
        return head->next;
    }
};
// @lc code=end

