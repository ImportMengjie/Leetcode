/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你不需要 保留 每个分区中各节点的初始相对位置。

示例 1：

输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]

提示：

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-list-lcci
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
    ListNode* partition(ListNode* head, int x) {
        ListNode tmp(-1);
        tmp.next = head;
        head = &tmp;

        ListNode* left = head;
        ListNode* cur = head->next;
        while(cur->next){
            if(cur->next->val<x)
                cur = cur->next;
        }

        while(cur){
            if(cur->val<x){
                ListNode* nxt = cur->next;
                ListNode* tmp = left->next;
                left->next = cur;
                cur->next = tmp;
                left = cur;
                cur = nxt;
            }else
                cur = cur->next;
        }
        return head->next;
    }
};
