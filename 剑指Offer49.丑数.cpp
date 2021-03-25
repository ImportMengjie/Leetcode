/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class Solution {

public:
    static vector<int> ans;

    static int i2, i3, i5;

    int nthUglyNumber(int n) {
        while(ans.size()<n){
            int cur = min({ans[i2]*2, ans[i3]*3, ans[i5]*5});
            ans.push_back(cur);
            if(cur == ans[i2]*2) i2++;
            if(cur == ans[i3]*3) i3++;
            if(cur == ans[i5]*5) i5++;
        }
        return ans[n-1];
    }
};

vector<int> Solution::ans = {1};
int Solution::i2=0, Solution::i3=0, Solution::i5;