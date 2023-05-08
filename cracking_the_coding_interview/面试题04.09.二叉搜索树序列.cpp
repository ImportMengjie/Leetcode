/*
从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。

给定一个由不同节点组成的二叉搜索树 root，输出所有可能生成此树的数组。

示例 1:

输入: root = [2,1,3]
输出: [[2,1,3],[2,3,1]]
解释: 数组 [2,1,3]、[2,3,1] 均可以通过从左向右遍历元素插入树中形成以下二叉搜索树
       2 
      / \ 
     1   3
示例 2:

输入: root = [4,1,null,null,3,2]
输出: [[4,1,3,2]]

提示：

二叉搜索树中的节点数在 [0, 1000] 的范围内
1 <= 节点值 <= 10^6
用例保证符合要求的数组数量不超过 5000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/bst-sequences-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <deque>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void dfs(deque<TreeNode*>& dq, vector<vector<int>>& ans,vector<int>& path){
        if(dq.empty()){
            ans.push_back(path);
            return;
        }
        int size = dq.size();
        for(int i=0;i<size; i++){
            TreeNode* p = dq.front();
            dq.pop_front();
            path.push_back(p->val);
            if(p->left) dq.push_back(p->left);
            if(p->right) dq.push_back(p->right);
            dfs(dq, ans, path);
            if(p->right) dq.pop_back();
            if(p->left) dq.pop_back();
            dq.push_back(p);
            path.pop_back();
        }
    }

    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return {{}};
        deque<TreeNode*> dq{root};
        vector<int> path;
        dfs(dq, ans, path);
        return ans;
    }
};