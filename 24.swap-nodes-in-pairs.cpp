/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode head_of_head(0);
        head_of_head.next = head;
        ListNode *p = &head_of_head;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            ListNode *t = p->next;
            p->next = p->next->next;
            t->next = p->next->next;
            p->next->next = t;
            p = p->next->next;
        }
        return head_of_head.next;
    }
};
