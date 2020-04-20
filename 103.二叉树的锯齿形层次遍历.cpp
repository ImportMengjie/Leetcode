/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.05%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    43.4K
 * Total Submissions: 80.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            if(depth%2)
                ans[depth].insert(ans[depth].begin(), pNode->val);
            else
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

