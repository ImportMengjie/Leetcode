/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
示例:
给定如下二叉树，以及目标和 target = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
 

提示：

节点总数 <= 10000
注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void dfs(vector<vector<int>> &ans, vector<int> &path, TreeNode* root, int target, int current){
        if(root){
            current += root->val;
            path.push_back(root->val);
            if(root->left==NULL && root->right==NULL){
                if(current==target)
                    ans.push_back(path);
            }else{
                if(root->left)
                    dfs(ans, path, root->left, target, current);
                if(root->right)
                    dfs(ans, path, root->right, target, current);
            }
            current-=root->val;
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, root, target, 0);
        return ret;
    }
};