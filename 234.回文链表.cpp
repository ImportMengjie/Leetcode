/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (41.21%)
 * Likes:    501
 * Dislikes: 0
 * Total Accepted:    89.5K
 * Total Submissions: 214K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

#define NULL 0
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        while(head){
            values.push_back(head->val);
            head = head->next;
        }
        int be=0, ed=values.size()-1;
        while (be<ed)
            if(values[be++]!=values[ed--])
                return false;
        return true;
    }
};
// @lc code=end

