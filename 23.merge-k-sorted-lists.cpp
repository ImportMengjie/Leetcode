/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode head(0);
        ListNode *p = &head;
        bool is_all_null = false;
        while (!is_all_null)
        {
            is_all_null = true;
            int min_node_ids = -1;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr)
                {
                    is_all_null = false;
                    if (min_node_ids < 0)
                        min_node_ids = i;
                    else
                        min_node_ids = lists[i]->val < lists[min_node_ids]->val ? i : min_node_ids;
                }
            }
            if (!is_all_null)
            {
                p->next = lists[min_node_ids];
                lists[min_node_ids] = lists[min_node_ids]->next;
                p = p->next;
            }
        }
        return head.next;
    }
};
