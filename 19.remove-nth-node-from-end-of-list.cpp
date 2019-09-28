/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <deque>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        deque<ListNode *> q;
        ListNode *p = head;
        while (p != NULL)
        {
            q.push_back(p);
            if (q.size() > n + 1)
                q.pop_front();
            p = p->next;
        }
        if (q.size() == n + 1)
        {
            q.front()->next = q.front()->next->next;
            delete q[1];
            return head;
        }
        else
        {
            delete q.front();
            return q.size() == 1 ? NULL : q[1];
        }
    }
};
