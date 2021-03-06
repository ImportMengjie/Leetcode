/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.63%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 47.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */
#include <vector>
#include <map>

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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,map<int,int> &m, int in_left, int in_right, int &post_ids){
        TreeNode *root = NULL;
        if(in_left<in_right){
            root = new TreeNode(postorder[post_ids--]);
            root->right = buildTree(inorder, postorder, m, m[root->val]+1, in_right, post_ids);
            root->left = buildTree(inorder, postorder, m, in_left, m[root->val], post_ids);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        int post_ids = postorder.size()-1;
        return buildTree(inorder, postorder, m, 0, inorder.size(), post_ids);
    }
};
// @lc code=end

