/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (66.08%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 54.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */
#include <string>
#include <array>

using namespace std;

// @lc code=start
class Trie {
private:
    class TrieNode{
        public:
            array<TrieNode*, 26> links;
            bool isEnd = false;
            TrieNode(){
                links.fill(nullptr);
            }
    };

    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char& c:word){
            if(!node->links[c-'a'])
                node->links[c-'a'] = new TrieNode();
            node = node->links[c-'a'];
        }
        node->isEnd = true;
    }

    TrieNode* searchPrefix(string word){
        TrieNode* node = root;
        for(char& c:word){
            if(node->links[c-'a'])
                node = node->links[c-'a'];
            else
                return nullptr;
        }
        return node;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* endNode = searchPrefix(word);
        return endNode&&endNode->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* endNode = searchPrefix(prefix);
        return endNode!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

