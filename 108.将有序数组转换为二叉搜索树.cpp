/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (70.05%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    61.9K
 * Total Submissions: 88K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
#include <vector>
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

    void buildTree(TreeNode **root, vector<int> &nums, int be, int ed){
        if(be<ed){
            int mid = (be+ed)/2;
            (*root)->val = nums[mid];
            (*root)->left = new TreeNode(0);
            buildTree(&(*root)->left,nums, be, mid);
            (*root)->right = new TreeNode(0);
            buildTree(&(*root)->right, nums, mid+1, ed);
        }else{
            delete (*root);
            (*root) = NULL;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = new TreeNode(0);
        buildTree(&root,nums, 0, nums.size());
        return root;
    }
};
// @lc code=end

