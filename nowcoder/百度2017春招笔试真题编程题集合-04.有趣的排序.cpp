/*
链接：https://www.nowcoder.com/questionTerminal/adc291e7e79f452c8b59243a5ce68d3a
来源：牛客网

度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作：
任取数组中的一个数然后将它放置在数组的最后一个位置。
问最少操作多少次可以使得数组从小到大有序？

输入描述:
首先输入一个正整数N，接下来的一行输入N个整数。(N <= 50, 每个数的绝对值小于等于1000)


输出描述:
输出一个整数表示最少的操作次数。
示例1
输入
4
19 7 8 25
输出
2
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    vector<int> sorted_nums;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        sorted_nums.push_back(num);
    }
    sort(sorted_nums.begin(), sorted_nums.end());
    int count=0;

    for(int i=0,j=0;i<nums.size();i++){
        if(nums[i]==sorted_nums[j]){
            j++;
            count++;
        }
    }
    cout<<n-count;
    return 0;
}
