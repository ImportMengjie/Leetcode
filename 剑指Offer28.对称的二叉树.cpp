/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.63%)
 * Likes:    726
 * Dislikes: 0
 * Total Accepted:    124.5K
 * Total Submissions: 245K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */
#define NULL 0

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
    bool isSymmetric(TreeNode* root1, TreeNode* root2){
        if(root1&&root2&&root1->val==root2->val)
            return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
        return root1==root2;
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};
// @lc code=end

