/*
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 
限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        dfs(ans, s, 0);
        return ans;
    }

    void dfs(vector<string> &ans, string& s, int i){
        if(i==s.size()-1) ans.push_back(s);
        else{
            set<int> st;
            for(int j=i;j<s.size();j++){
                if(st.find(s[j])==st.end()){
                    st.insert(s[j]);
                    swap(s[i],s[j]);
                    dfs(ans, s, i+1);
                    swap(s[j],s[i]);
                }
            }
        }
    }
    
};
