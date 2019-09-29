/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode head_of_head(0);
        head_of_head.next = head;
        ListNode *p = &head_of_head;

        stack<ListNode *> s;
        while (p != nullptr)
        {
            ListNode *h = p;
            p = p->next;
            for (int i = 0; i < k; i++)
            {
                if (p != nullptr)
                {
                    s.push(p);
                    p = p->next;
                }
                else
                    break;
            }
            if (s.size() == k)
            {
                h->next = s.top();
                while (!s.empty())
                {
                    ListNode *top = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        top->next = p;
                        p = top;
                    }
                    else
                        top->next = s.top();
                }
            }
        }
        return head_of_head.next;
    }
};
