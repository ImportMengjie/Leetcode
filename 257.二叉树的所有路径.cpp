/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (63.12%)
 * Likes:    262
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 58.6K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */
#include <vector>
#include <string>
#include <stack>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root){
            stack<pair<TreeNode*, string>> s;
            s.push({root,""});
            while (s.size()) {
                TreeNode* p = s.top().first;
                string path = s.top().second;
                s.pop();
                path.append("->"+to_string(p->val));
                if(!p->left&&!p->right)
                    ans.push_back(path.substr(2));
                if(p->left)
                    s.push({p->left, path});
                if(p->right)
                    s.push({p->right, path});
            }
        }
        return ans;
    }
};
// @lc code=end

