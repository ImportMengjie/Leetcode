/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.80%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    134.9K
 * Total Submissions: 190.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// Definition for a binary tree node.
#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

// @lc code=start
class Solution {
public:

    void backtrack(TreeNode *root, vector<int> &ans){
        if(root){
            if(root->left)
                backtrack(root->left, ans);
            ans.push_back(root->val);
            if(root->right)
                backtrack(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        backtrack(root, ans);
        return ans;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(stk.size()||p){
            while(p){
                stk.push(p);
                p = p->left;
            }
            ans.push_back(stk.top()->val);
            p = stk.top()->right;
            stk.pop();
        }
        return ans;
    }

};
// @lc code=end

