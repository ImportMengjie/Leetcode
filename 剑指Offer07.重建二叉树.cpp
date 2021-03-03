/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.67%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    59.5K
 * Total Submissions: 91.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left,int right, int& preorder_idx, map<int,int>& m){
        TreeNode* root = NULL;
        if(left<right){
            root = new TreeNode(preorder[preorder_idx++]);
            root->left = buildTree(preorder, inorder, left, m[root->val], preorder_idx, m);
            root->right = buildTree(preorder, inorder, m[root->val]+1, right, preorder_idx, m);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        int preorder_idx = 0;
        return buildTree(preorder, inorder, 0, preorder.size(), preorder_idx, m);
    }
};
// @lc code=end

