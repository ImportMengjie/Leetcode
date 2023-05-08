/*
下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。

示例1:

 输入：num = 2（或者0b10）
 输出：[4, 1] 或者（[0b100, 0b1]）
示例2:

 输入：num = 1
 输出：[2, -1]
提示:

num的范围在[1, 2147483647]之间；
如果找不到前一个或者后一个满足条件的正数，那么输出 -1。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/closed-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        int less = -1, great = -1;
        array<bool, 32> arr{0};
        for(int i=0;i<32;i++)
            arr[i] = num & (1<<i);
        
        int rightCount = arr[0]?1:0;
        for(int i=1;i<31;i++){
            if(arr[i]==1&&arr[i-1]==0){
                less = num>>(i+1)<<(i+1);
                less |= (1<<(i-1));
                for(int j=0;j<rightCount;j++)
                    less |= (1<<(i-j-2));
                break;
            }
            rightCount += arr[i]?1:0;
        }
        rightCount = arr[0]?1:0;
        for(int i=1;i<31;i++){
            if(arr[i]==0&&arr[i-1]==1){
                great = num>>i<<i;
                great |= 1<<i;
                for(int j=0;j<rightCount-1;j++)
                    great |= (1<<j);
                break;
            }
            rightCount += arr[i];
        }
        return {great, less};
    }
};
