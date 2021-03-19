/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int left, int right){
        if(left<right){
            int t = arr[left];
            while(left<right){
                while(arr[right]>t&&left<right)
                    right--;
                arr[left] = arr[right];
                while(arr[left]<=t&&left<right)
                    left++;
                arr[right] = arr[left];
            }
            arr[left] = t;
        }
        return left;
    }

    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        if(k==0) return {};
        if(arr.size()<=k) return arr;
        priority_queue<int,vector<int>,greater<int>> Q;
        int i = 0;
        for(;i<k;i++)
            Q.push(arr[i]);
        for(;i<arr.size();i++){
            if(Q.top()>arr[i]){
                Q.pop();
                Q.push(arr[i]);
            }
        }
        vector<int> ret;
        for(i=0;i<k;i++){
            ret.push_back(Q.top());
            Q.pop();
        }
        return ret;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()<=k) return arr;
        if(k==0) return {};
        int left = 0, right = arr.size()-1;
        int mid = partition(arr, left, right);
        while(mid!=k-1){
            if(mid>k-1)
                right = mid-1;
            else
                left = mid+1;
            mid = partition(arr, left, right);
        }
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};