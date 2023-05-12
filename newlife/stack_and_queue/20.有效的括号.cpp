/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:

    unordered_map<char,char> m = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

public:
    bool isValid(string s) {
        stack<char> stk;
        for(char& c:s) {
            if(!m.count(c)) stk.push(c);
            else if(stk.size()&&stk.top()==m[c]) stk.pop();
            else return false;
        }
        return stk.empty();
    }
};
// @lc code=end

