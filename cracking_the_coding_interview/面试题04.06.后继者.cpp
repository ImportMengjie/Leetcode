/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define NULL 0
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        if(p->right){
            successor = p->right;
            while(successor->left)
                successor = successor->left;
        } else{
            TreeNode* node = root;
            while(node){
                if(node->val>p->val){
                    successor = node;
                    node = node->left;
                } else{
                    node = node->right;
                }
            }
        }
        return successor;
    }

    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* pre=NULL, * cur=root;
        while(st.size() || cur){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(pre == p) return cur;
            pre = cur;
            cur = cur->right;
        }
        return NULL;
    }
};