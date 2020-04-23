/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (59.03%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    42.6K
 * Total Submissions: 72K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
#include <vector>
#include <stack>
#include <numeric>

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

    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        stack<pair<TreeNode*,vector<int>>> s;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        int target = 0;
        vector<int> temp;
        temp.push_back(root->val);
        s.push({root,temp});
        while(!s.empty()){
            TreeNode* p = s.top().first;
            vector<int> path = s.top().second;
            s.pop();
            if(!(p->left||p->right)&&accumulate(path.begin(),path.end(),0)==sum){
                ans.push_back(path);
            }
            if(p->right){
                vector<int> t(path);
                t.push_back(p->right->val);
                s.push({p->right, t});
            }
            if(p->left){
                vector<int> t(path);
                t.push_back(p->left->val);
                s.push({p->left, t});
            }
        }
        return ans;
    }
};
// @lc code=end

