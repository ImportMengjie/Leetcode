/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// @lc code=start
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(root->val>key){
                root->left = deleteNode(root->left, key);
                return root;
            }else if(root->val<key){
                root->right = deleteNode(root->right, key);
                return root;
            }else{
                if(!root->left && !root->right) return nullptr;
                else if(!root->left) return root->right;
                else if(!root->right) return root->left;
                else{
                    TreeNode* successor = root->right;
                    while(successor->left)
                        successor = successor->left;
                    root->right = deleteNode(root->right, successor->val);
                    successor->left = root->left;
                    successor->right = root->right;
                    return successor;
                }
            }
        }else
            return nullptr;
    }
};
// @lc code=end

