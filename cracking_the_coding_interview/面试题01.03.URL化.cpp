/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

 

示例 1：

输入："Mr John Smith    ", 13
输出："Mr%20John%20Smith"
示例 2：

输入："               ", 5
输出："%20%20%20%20%20"
 

提示：

字符串长度在 [0, 500000] 范围内。


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/string-to-url-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space_count = 0;
        for(int i=0;i<length;i++)
            if(S[i]==' ') space_count++;
        int replace_size = length + 2 * space_count;
        S.resize(replace_size);
        int i = length - 1;
        int j = replace_size - 1;
        while(i>=0&&i!=j){
            if(S[i]==' '){
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else{
                S[j--] = S[i];
            }
            i--;
        }
        return S;
    }
};
