/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.82%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 104.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* prev = root;
        while (s.size())
        {
            TreeNode* top = s.top();
            if(prev!=top->right&&prev!=top->left){
                if(top->right)
                    s.push(top->right);
                if(top->left)
                    s.push(top->left);
            }

            if(!(top->left||top->right)){
                ans.push_back(top->val);
                s.pop();
            }
            if(prev==top->right||prev==top->left){
                ans.push_back(top->val);
                s.pop();
            }
            prev = top;
        }
        return ans;
    }
};
// @lc code=end

