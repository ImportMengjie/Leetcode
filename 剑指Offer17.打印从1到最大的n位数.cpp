/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 
说明：

用返回一个整数列表来代替打印
n 为正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& ret, string& numbers, int index, int n){
        if(index<n){
            for(int i=0;i<10;i++){
                numbers[index]=i+'0';
                dfs(ret, numbers, index+1, n);
            }
        } else
            ret.push_back(stoi(numbers));
    }

    vector<int> printNumbers(int n) {
        string numbers(n, '0');
        vector<int> ret;
        dfs(ret, numbers, 0, n);
        ret.erase(ret.begin());
        return ret;
    }
};
