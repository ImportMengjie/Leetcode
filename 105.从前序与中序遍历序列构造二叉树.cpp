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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,map<int,int> &m, int in_left, int in_right, int &pre_ids){
        TreeNode *root = NULL;
        if(in_left<in_right){
            root = new TreeNode(preorder[pre_ids++]);
            root->left = buildTree(preorder, inorder, m, in_left, m[root->val], pre_ids);
            root->right = buildTree(preorder, inorder, m, m[root->val]+1, in_right, pre_ids);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        int pre_ids = 0;
        return buildTree(preorder, inorder, m, 0, inorder.size(), pre_ids);
        
    }
};
// @lc code=end

