/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (63.65%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 11.9K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给定一个字符串数组 words，找到 length(word[i]) * length(word[j])
 * 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
 * 
 * 示例 1:
 * 
 * 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出: 16 
 * 解释: 这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2:
 * 
 * 输入: ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出: 4 
 * 解释: 这两个单词为 "ab", "cd"。
 * 
 * 示例 3:
 * 
 * 输入: ["a","aa","aaa","aaaa"]
 * 输出: 0 
 * 解释: 不存在这样的两个单词。
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<unsigned int,size_t> hashmap;
        for(auto& word:words){
            unsigned int bitmap = 0;
            for(char& c:word)
                bitmap |= 1<<(c-'a');
            if(hashmap.count(bitmap))
                hashmap[bitmap]=max(hashmap[bitmap],word.size());
            else
                hashmap[bitmap] = word.size();
        }
        size_t max_product = 0;
        for(auto& x:hashmap){
            for(auto& y:hashmap){
                if((x.first&y.first)==0){
                    max_product = max(max_product, x.second*y.second);
                }
            }
        }
        return max_product;
    }
};
// @lc code=end

