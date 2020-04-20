/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.35%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    106.4K
 * Total Submissions: 172.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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


// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int depth = -1;
        while (!q.empty())
        {
            TreeNode *pNode = q.front().first;
            if(depth<q.front().second){
                ans.push_back(vector<int>());
                depth++;
            }
            ans[depth].push_back(pNode->val);
            if(pNode->left)
                q.push({pNode->left,depth+1});
            if(pNode->right)
                q.push({pNode->right,depth+1});
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

