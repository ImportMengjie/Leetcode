/*
一个数轴上共有N个点，第一个点的坐标是度度熊现在位置，第N-1个点是度度熊的家。现在他需要依次的从0号坐标走到N-1号坐标。
但是除了0号坐标和N-1号坐标，他可以在其余的N-2个坐标中选出一个点，并直接将这个点忽略掉，问度度熊回家至少走多少距离？

输入描述:
输入一个正整数N, N <= 50。

接下来N个整数表示坐标，正数表示X轴的正方向，负数表示X轴的负方向。绝对值小于等于100

输出描述:
输出一个整数表示度度熊最少需要走的距离。

输入例子1:
4
1 4 -1 3

输出例子1:
4
*/
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int count_distance(int& x, int& y){
    return abs(y-x);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    if(nums.size()<=1) return -1;

    int total_count = 0;
    int max_reduce = 0;
    for(int i=1;i<nums.size();i++){
        total_count+=count_distance(nums[i],nums[i-1]);
        if(i<nums.size()-1)
            max_reduce = max(max_reduce, count_distance(nums[i-1],nums[i])+count_distance(nums[i],nums[i+1])-count_distance(nums[i-1], nums[i+1]));
        
    }
    cout<<total_count-max_reduce;
    return 0;
}