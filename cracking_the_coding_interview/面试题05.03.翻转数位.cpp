/*
给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。

示例 1：

输入: num = 1775(110111011112)
输出: 8
示例 2：

输入: num = 7(01112)
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-bits-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        int cur = 0, rev = 0, ans = 1;
        for(int i=0;i<32;i++) {
            if(num&1){
                cur++;
                rev++;
            } else{
                rev = cur + 1;
                cur = 0;
            }
            ans = max(ans, rev);
            num >>= 1;
        }
        return ans;
    }
};
