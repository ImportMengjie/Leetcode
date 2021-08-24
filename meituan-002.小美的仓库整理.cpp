/*
小美是美团仓库的管理员，她会根据单据的要求按顺序取出仓库中的货物，每取出一件货物后会把剩余货物重新堆放，使得自己方便查找。已知货物入库的时候是按顺序堆放在一起的。如果小美取出其中一件货物，则会把货物所在的一堆物品以取出的货物为界分成两堆，这样可以保证货物局部的顺序不变。
已知货物最初是按 1~n 的顺序堆放的，每件货物的重量为 w[i] ,小美会根据单据依次不放回的取出货物。请问根据上述操作，小美每取出一件货物之后，重量和最大的一堆货物重量是多少？

格式：


输入：
- 输入第一行包含一个正整数 n ，表示货物的数量。
- 输入第二行包含 n 个正整数，表示 1~n 号货物的重量 w[i] 。
- 输入第三行有 n 个数，表示小美按顺序取出的货物的编号，也就是一个 1~n 的全排列。
输出：
- 输出包含 n 行，每行一个整数，表示每取出一件货物以后，对于重量和最大的一堆货物，其重量和为多少。
示例：


输入：
     5
     3 2 4 4 5 
     4 3 5 2 1
输出：
     9
     5
     5
     3
     0
解释：
原本的状态是 {{3,2,4,4,5}} ，取出 4 号货物后，得到 {{3,2,4},{5}} ，第一堆货物的和是 9 ，然后取出 3 号货物得到 {{3,2}{5}} ，此时第一堆和第二堆的和都是 5 ，以此类推。
提示：

1 <= n,m <= 50000
1 <= w[i] <= 100
请注意，本题需要自行编写「标准输入」和「标准输出」逻辑，以及自行 import/include 需要的 library。了解书写规则

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/TJZLyC
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DSet{
private:
    int count;
    vector<int> weight;
    vector<int> parent;

public:
    DSet(const vector<int>& w)
    :count(w.size()),weight(w), parent(w.size(), 0){
        for(int i=0;i<count;i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    int merge(int a, int b){
        int roota = find(a);
        int rootb = find(b);
        if(roota==rootb) return roota;
        parent[rootb] = roota;
        weight[roota] += weight[rootb];
        return roota;
    }

    int getWeight(int a){
        return weight[find(a)];
    }
};

int main(){
    int len;
    cin>>len;
    vector<int> nums(len);
    vector<int> take(len);
    for(int i=0;i<len;i++)
        cin>>nums[i];
    for(int i=0;i<len;i++)
        cin>>take[i];
    vector<int> ans{0};
    vector<bool> vis(len, false);

    DSet d(nums);
    for(int i=len-1;i>0;i--){
        int pos = take[i] - 1;
        int parent = pos;
        vis[pos] = true;
        if(pos>0&&vis[pos-1])
            parent = d.merge(pos, pos-1);
        if(pos<len-1&&vis[pos+1])
            parent = d.merge(pos, pos+1);
        ans.push_back(max(ans.back(), d.getWeight(parent)));
    }
    reverse(ans.begin(), ans.end());
    for(int& num:ans)
        cout<<num<<endl;
    return 0;
}
