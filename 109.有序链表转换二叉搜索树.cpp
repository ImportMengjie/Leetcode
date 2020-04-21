/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (71.23%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 34.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// @lc code=start
class Solution {
public:

    ListNode* findMidNode(ListNode *head){
        ListNode* prevNode = NULL;
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while(fastNode&&fastNode->next){
            prevNode = slowNode;
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        if(prevNode)
            prevNode->next = NULL;
        return slowNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* mid = findMidNode(head);
        TreeNode* root = new TreeNode(mid->val);
        if(head!=mid){
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(mid->next);
        }
        return root;
    }
};
// @lc code=end

