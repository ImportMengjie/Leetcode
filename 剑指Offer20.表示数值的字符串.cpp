/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>

using namespace std;

class Solution {
public:
    bool scanUnsignedInteger(string& s, int& idx){
        int before = idx;
        while(idx<s.size()&&s[idx]>='0'&&s[idx]<='9') idx++;
        return idx>before;
    }

    bool scanInteger(string& s, int& idx){
        if(idx<s.size()&&(s[idx]=='+'||s[idx]=='-')) idx++;
        return scanUnsignedInteger(s, idx);
    }

    bool isNumber(string s) {
        bool isEmpty = true;
        for(char& c:s)
            if(c!=' '){
                isEmpty = false;
                break;
            }
        if(isEmpty) return false;
        int idx = s.find_first_not_of(" \n\r");
        bool numeric = scanInteger(s, idx);
        if(s[idx]=='.'){
            idx++;
            numeric = scanUnsignedInteger(s, idx)||numeric;
        }
        if(s[idx]=='e'||s[idx]=='E'){
            idx++;
            numeric = numeric && scanInteger(s, idx);
        }
        return numeric && idx==s.find_last_not_of(" \n\r")+1;
    }
};