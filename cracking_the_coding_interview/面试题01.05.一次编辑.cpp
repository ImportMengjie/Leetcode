/*
字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

示例 1:
输入: 
first = "pale"
second = "ple"
输出: True

示例 2:
输入: 
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        string& long_str = first.size()>second.size()?first:second;
        string& short_str = first.size()<=second.size()?first:second;
        if(long_str.size()-short_str.size()>1) return false;
        if(short_str.empty()) return true;
        int i=0,j=0;
        bool oneEdit = false;
        while(i<long_str.size()){
            if(long_str[i]==short_str[j]){
                i++,j++;
            }else{
                if(oneEdit) return false;
                oneEdit = true;
                i++;
                if(long_str.size()==short_str.size()) j++;
            }
        }
        return true;
    }
};
