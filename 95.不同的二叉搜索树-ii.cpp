/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (62.28%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 41.9K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

// @lc code=start
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> all_trees;
        if(start>end){
            all_trees.push_back(NULL);
        }else{
            for(int i=start;i<=end;i++){
                vector<TreeNode*> left_trees = generateTrees(start, i-1);
                vector<TreeNode*> right_trees = generateTrees(i+1,end);
                for(TreeNode *left:left_trees)
                    for(TreeNode *right: right_trees){
                        TreeNode * root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        all_trees.push_back(root);
                    }
            }
        }
        return all_trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};
// @lc code=end

