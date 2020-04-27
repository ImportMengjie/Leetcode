/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.73%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 88K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */
#define NULL 0
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

class Solution {
public:
    int max_value = 1<<31;

    int maxPathSum2(TreeNode* root) {
        if(!root) return 0;
        int left_value = max(maxPathSum2(root->left), 0);
        int right_value = max(maxPathSum2(root->right), 0);
        max_value = max(max_value, left_value+right_value+root->val);
        return root->val+max(left_value,right_value);
    }
    int maxPathSum(TreeNode* root) {
        maxPathSum2(root);
        return max_value;
    }
};
// @lc code=end

