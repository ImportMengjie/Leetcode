/*
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-balance-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <cmath>
#include <algorithm>
#define NULL 0

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }

    int depth(TreeNode* root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left==-1||right==-1||abs(left-right)>1) return -1;
        else return std::max(left, right) + 1;
    }
};