/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (64.70%)
 * Likes:    526
 * Dislikes: 0
 * Total Accepted:    58.7K
 * Total Submissions: 90K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    ListNode* merge(ListNode* left, ListNode* right){
        static ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = NULL;
        ListNode* p = dummy_head;
        while (left&&right) {
            if(left->val<right->val){
                p->next = left;
                left = left->next;
            }
            else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = nullptr;
        while(left){
            p->next = left;
            left = left->next;
            p = p->next;
            p->next = nullptr;
        }
        while(right){
            p->next = right;
            right = right->next;
            p = p->next;
            p->next = nullptr;
        }
        return dummy_head->next;
    }

    ListNode* cut(ListNode *list, int len){
        len--;
        while(len--){
            if(list)
                list = list->next;
            else break;
        }
        if(list){
            ListNode* next = list->next;
            list->next = nullptr;
            return next;
        }else
            return nullptr;
    }

    ListNode* sortList(ListNode* head) {
        ListNode t(-1);
        ListNode* dummy_head = &t;
        dummy_head->next = head;

        ListNode* cur = head;
        int len = 0;
        while (cur&&++len)
            cur = cur->next;
        
        for(int step=1;step<len;step*=2){
            ListNode* tail = dummy_head;
            ListNode* left = dummy_head->next;

            while (left) {
                ListNode* right = cut(left, step);
                ListNode* new_left = cut(right, step);
                tail->next = merge(left, right);
                while(tail->next)
                    tail = tail->next;
                left = new_left;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

