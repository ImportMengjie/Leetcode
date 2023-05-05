/*
编写一个函数，检查输入的链表是否是回文的。

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindrome-linked-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define NULL 0

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* half = halfListNode(head);
        reverseListNode(half);
        ListNode* mid = half->next;
        ListNode* p = head;

        while(mid){
            if(mid->val!=p->val)
                return false;
            mid = mid->next;
            p = p->next;
        }
        reverseListNode(half);
        return true;
    }

    void reverseListNode(ListNode* head){
        ListNode* cur = head->next;
        ListNode* pre = NULL;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = pre;
    }

    ListNode* halfListNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
