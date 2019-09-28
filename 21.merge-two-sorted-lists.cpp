/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *phead = &head;
        ListNode *p = phead;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        if (l1 != nullptr)
            p->next = l1;
        if (l2 != nullptr)
            p->next = l2;
        return phead->next;
    }
};
