/*
链接：https://www.nowcoder.com/questionTerminal/908255677b6f4c18a9074c12f21acd59?f=discussion
来源：牛客网

现在有n个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，要求这两个人每一个人分到的物品的价值总和相同（个数可以不同，总价值相同即可），剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。

输入描述:
第一行输入一个整数 T，代表有 T 组测试数据。

对于每一组测试数据，一行输入一个整数 n ，代表物品的个数。

接下来 n 个数，a[i] 代表每一个物品的价值。

1<= T <= 10
1 <= n <= 15
1 <= a[i] <= 100000



输出描述:
对于每一组测试数据，输出一个答案代表最少需要扔的价值。
示例1
输入
1
5
30 60 5 15 30
输出
20
说明
样例解释，扔掉第三个和第四个物品，然后将第一个物品和第五个物品给第一个人，第二个物品给第二个人，每一个人分到的价值为6060，扔掉的价值为2020。
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dfs(vector<int>& nums, int i, int result1, int result2){
    if(i>=nums.size()){
        if(result1==result2)
            return result1;
        else
            return 0;
    }
    int a = dfs(nums, i+1, result1+nums[i], result2);
    int b = dfs(nums, i+1, result1, result2+nums[i]);
    int c = dfs(nums, i+1, result1, result2);
    return max({a,b,c});
}

int main(){
    int T,n;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n;
        int sum = 0;
        vector<int> nums(n, 0);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            sum+=nums[i];
        }
        int res = dfs(nums, 0, 0, 0);
        cout<<sum-res*2<<endl;
    }
    return 0;
}