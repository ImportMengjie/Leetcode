/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (31.69%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 28.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: []
 * 
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 * 
 */
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        vector<vector<string>> ans;

        map<string,vector<string>> allComboDict;
        for(string& word:wordList){
            for(int i=0;i<beginWord.size();i++){
                string key = word.substr(0,i)+"*"+word.substr(i+1,beginWord.size());
                if(allComboDict.find(key)==allComboDict.end())
                    allComboDict[key] = vector<string>();
                allComboDict[key].push_back(word);
            }
        }
        queue<pair<string,vector<string>>> q;
        q.push({beginWord, {beginWord}});
        while(q.size()){
            string e = q.front().first;
            vector<string> path = q.front().second;
            q.pop();
            if(!ans.empty()&&ans[0].size()<=path.size())
                break;
            for(int i=0;i<beginWord.size();i++){
                string key = e.substr(0,i)+"*"+ e.substr(i+1,beginWord.size());
                if(allComboDict.find(key)!=allComboDict.end()){
                    for(string& word:allComboDict[key]){
                        if(word==endWord){
                            path.push_back(word);
                            if(ans.empty()||ans[0].size()==path.size())
                                ans.push_back(path);
                            path.pop_back();
                        }
                        else if(find(path.begin(),path.end(),word)==path.end()){
                            path.push_back(word);
                            if(ans.empty()||path.size()<=ans[0].size()){
                                q.push({word, path});
                            }
                            path.pop_back();
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

