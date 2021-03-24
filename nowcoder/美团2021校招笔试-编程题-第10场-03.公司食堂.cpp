/*
小美和小团所在公司的食堂有N张餐桌，从左到右摆成一排，每张餐桌有2张餐椅供至多2人用餐，公司职员排队进入食堂用餐。小美发现职员用餐的一个规律并告诉小团：当男职员进入食堂时，他会优先选择已经坐有1人的餐桌用餐，只有当每张餐桌要么空着要么坐满2人时，他才会考虑空着的餐桌；

当女职员进入食堂时，她会优先选择未坐人的餐桌用餐，只有当每张餐桌都坐有至少1人时，她才会考虑已经坐有1人的餐桌；

无论男女，当有多张餐桌供职员选择时，他会选择最靠左的餐桌用餐。现在食堂内已有若干人在用餐，另外M个人正排队进入食堂，小团会根据小美告诉他的规律预测排队的每个人分别会坐哪张餐桌。

输入描述:
第一行输入一个整数T（1<=T<=10），表示数据组数。

每组数据占四行，第一行输入一个整数N（1<=N<=500000）；

第二行输入一个长度为N且仅包含数字0、1、2的字符串，第i个数字表示左起第i张餐桌已坐有的用餐人数；

第三行输入一个整数M（1<=M<=2N且保证排队的每个人进入食堂时都有可供选择的餐桌）；

第四行输入一个长度为M且仅包含字母M、F的字符串，若第i个字母为M，则排在第i的人为男性，否则其为女性。

输出描述:
每组数据输出占M行，第i行输出一个整数j（1<=j<=N），表示排在第i的人将选择左起第j张餐桌用餐。

输入例子1:
1
5
01102
6
MFMMFF

输出例子1:
2
1
1
3
4
4
*/
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

void printNumber(vector<int> numbers, vector<char> sex){
    priority_queue<int, vector<int>, greater<int>> pq0;
    priority_queue<int, vector<int>, greater<int>> pq1;

    for(int i=0;i<numbers.size();i++)
        if(numbers[i]==0) pq0.push(i);
        else if(numbers[i]==1) pq1.push(i);
    for(int m=0;m<sex.size();m++){
        if(sex[m]=='M'){
            if(pq1.size()){
                cout<<pq1.top()+1<<endl;
                pq1.pop();
            } else{
                cout<<pq0.top()+1<<endl;
                pq1.push(pq0.top());
                pq0.pop();
            }
        }else{
            if(pq0.size()){
                cout<<pq0.top()+1<<endl;
                pq1.push(pq0.top());
                pq0.pop();
            } else {
                cout<<pq1.top()+1<<endl;
                pq1.pop();
            }
        }
    }
}

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int number_table;
        vector<int> table_people_num;
        vector<char> table_people_sex;
        cin>>number_table;
        string temp;
        cin>>temp;
        for(char& c:temp)
            table_people_num.push_back(c-'0');
        cin>>number_table;
        cin>>temp;
        for(char& c:temp)
            table_people_sex.push_back(c);
        printNumber(table_people_num, table_people_sex);
    }
    return 0;
}