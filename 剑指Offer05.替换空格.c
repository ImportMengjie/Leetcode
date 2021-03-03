/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdlib.h>

char* replaceSpace(char* s){
    int replaceCount=0;
    int orginCount=0;
    while (s[orginCount]!='\0') {
        if(s[orginCount]==' ')
            replaceCount+=2;
        orginCount++;
        replaceCount++;
    }
    s = (char*)realloc(s, (replaceCount+1)*sizeof(char));
    while (replaceCount>orginCount) {
        if(s[orginCount]!=' ')
            s[replaceCount--]=s[orginCount--];
        else{
            s[replaceCount--] = '0';
            s[replaceCount--] = '2';
            s[replaceCount--] = '%';
            orginCount--;
        }
    }
    return s;
}