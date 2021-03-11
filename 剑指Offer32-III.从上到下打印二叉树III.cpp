/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 
提示：

节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;

        stack<TreeNode*> stks[2];
        int current = 0, next = 1;
        stks[current].push(root);
        ret.push_back({});
        while(stks[0].size()||stks[1].size()){
            TreeNode* p = stks[current].top();
            stks[current].pop();
            ret.back().push_back(p->val);
            if(current==0){
                if(p->left) stks[next].push(p->left);
                if(p->right) stks[next].push(p->right);
            }else{
                if(p->right) stks[next].push(p->right);
                if(p->left) stks[next].push(p->left);
            }
            if(stks[current].empty()){
                next = 1 - next;
                current = 1 - current;
                ret.push_back({});
            }
        }
        ret.erase(ret.end());
        return ret;
    }
};