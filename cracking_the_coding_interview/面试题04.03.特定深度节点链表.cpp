/*
给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

示例：

输入：[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/list-of-depth-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(!tree) return {};
        queue<TreeNode*> qu;
        qu.push(tree);
        vector<ListNode*> ret;
        ListNode* head = new ListNode(-1);
        while(qu.size()){
            int size = qu.size();
            ListNode* pre = head;
            while(size--){
                ListNode* node = new ListNode(qu.front()->val);
                pre->next = node;
                pre = node;
                if(qu.front()->left) qu.push(qu.front()->left);
                if(qu.front()->right) qu.push(qu.front()->right);
                qu.pop();
            }
            ret.push_back(head->next);
        }
        return ret;
    }
};