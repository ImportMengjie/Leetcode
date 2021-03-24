/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (55.58%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 129.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */

// @lc code=start

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
    int sumOfLeftLeaves(TreeNode* root,bool is_left) {
        if(root){
            if(!root->left&&!root->right&&is_left)
                return root->val;
            int count = 0;
            if(root->left)
                count+=sumOfLeftLeaves(root->left, true);
            if(root->right)
                count+=sumOfLeftLeaves(root->right, false);
            return count;
        }
        return 0;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root)
            return sumOfLeftLeaves(root, false);
        return 0;
    }
};
// @lc code=end

