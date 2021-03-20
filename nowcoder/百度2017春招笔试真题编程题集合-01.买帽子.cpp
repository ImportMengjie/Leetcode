/*
度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？

输入描述:
首先输入一个正整数N（N <= 50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）

输出描述:
如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1

输入例子1:
10
10 10 10 10 20 20 30 30 40 40

输出例子1:
30
*/

#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,less<int>> nums;
    set<int> st;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(st.find(t)==st.end()){
            st.insert(t);
            if(nums.size()<3)
                nums.push(t);
            else if(nums.top()>t){
                nums.pop();
                nums.push(t);
            }
        }
    }
    if(nums.size()==3)
        cout<<nums.top();
    else
        cout<<-1;
    return 0;
}