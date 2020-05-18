/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (43.62%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 24.3K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 * 
 * 示例:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 说明:
 * 
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 * 
 */
#include <string>
#include <array>
#include <queue>

using namespace std;

// @lc code=start
class WordDictionary {
private:

    class TrieNode{
    public:
        array<TrieNode*,26> links;
        bool isEnd = false;
        TrieNode(){
            links.fill(nullptr);
        }

        TrieNode* getValue(char c){
            return links[c-'a'];
        }

        void putKey(char c){
            links[c-'a'] = new TrieNode();
        }
    };

    TrieNode* root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char& c:word){
            if(!node->getValue(c))
                node->putKey(c);
            node = node->getValue(c);
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<TrieNode*> q;
        q.push(root);
        TrieNode* node;
        int ids = 0;
        while (q.size()&&ids<word.size()) {
            int len = q.size();
            char c = word[ids];
            for(int i=0;i<len;i++){
                node = q.front();
                q.pop();
                vector<TrieNode*> needAdd;
                if(c=='.'){
                    for(TrieNode* n:node->links)
                        if(n) needAdd.push_back(n);
                }
                else
                    if(node->getValue(c)) needAdd.push_back(node->getValue(c));
                for(TrieNode* n: needAdd){
                    if(ids==word.size()-1){
                        if(n->isEnd) return true;
                    }
                    else
                        q.push(n);
                }
            }
            ids++;
        }
        return false;

        // for(int i=0;i<word.size()&&q.size();i++){
        //     node = q.front();
        //     q.pop();
        //     if(word[i]!='.'){
        //         if(node->getValue(word[i]))
        //             q.push(node);
        //         else return false;
        //     }else{
        //         for(TrieNode*& n:node->links)
        //             if(n) q.push(n);
        //     }
        // }

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

