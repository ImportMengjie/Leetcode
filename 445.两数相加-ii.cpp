/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode.cn/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (59.78%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    104K
 * Total Submissions: 173.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入：l1 = [7,2,4,3], l2 = [5,6,4]
 * 输出：[7,8,0,7]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[8,0,7]
 * 
 * 
 * 示例3：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 100]
 * 0 <= node.val <= 9
 * 输入数据保证链表代表的数字无前导 0
 * 
 * 
 * 
 * 
 * 进阶：如果输入链表不能翻转该如何解决？
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
    ListNode* reverse(ListNode* root){
        ListNode* pre = nullptr;
        ListNode* cur = root;
        while(cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* root = new ListNode(-1);
        ListNode* p = root;
        int carry = 0;
        while(l1||l2||carry!=0){
            int a = l1?l1->val:0;
            int b = l2?l2->val:0;
            int val = a+b+carry;
            carry = val/10;
            val = val%10;
            p->next = new ListNode(val);
            p = p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return reverse(root->next);
    }
};
// @lc code=end

