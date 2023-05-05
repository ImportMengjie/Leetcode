/*
给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-lists-lcci
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1&&l2){
            ListNode* node = new ListNode((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ListNode* node = new ListNode((l1->val+carry)%10);
            carry = (l1->val+carry)/10;
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            ListNode* node = new ListNode((l2->val+carry)%10);
            carry = (l2->val+carry)/10;
            cur->next = node;
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry){
            cur->next = new ListNode(carry);
        }
        return head->next;
    }
};
