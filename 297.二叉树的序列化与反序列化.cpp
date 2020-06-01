/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (45.94%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 50.6K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */

#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size())
        {
            TreeNode* p = q.front();
            q.pop();
            if(p){
                ans.append(to_string(p->val));
                q.push(p->left);
                q.push(p->right);
            }else
                ans.append("nil");
            if(q.size())
                ans.push_back(',');
        }
        return ans;
    }
    string getNextString(const string &data, int &i){
        int t = i;
        int end = data.size();
        if((end=data.find(',',t))!=string::npos){
            i = end+1;
            return data.substr(t, end-t);
        }
        else{
            i = data.size();
            return data.substr(t);
        }
        return "";
    }

    void handle_element(queue<TreeNode*>& q, TreeNode*& p, const string& data){
        if(data!="nil"){
            p = new TreeNode(stoi(data));
            q.push(p);
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data.size()){
            int data_ids = 0;
            string root_data = getNextString(data, data_ids);
            if(root_data=="nil") return root;
            root = new TreeNode(stoi(root_data));
            queue<TreeNode*> q;
            q.push(root);
            while (data_ids<data.size())
            {
                string s = getNextString(data, data_ids);
                TreeNode* p = q.front();
                q.pop();
                handle_element(q, p->left, s);
                if(data_ids<data.size()){
                    s = getNextString(data, data_ids);
                    handle_element(q, p->right, s);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

