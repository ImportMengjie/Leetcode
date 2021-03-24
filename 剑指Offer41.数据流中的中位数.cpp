/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]

限制：

最多会对 addNum、findMedian 进行 50000 次调用。
注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <queue>

using namespace std;

class MedianFinder {
private:

    priority_queue<int,vector<int>, less<int>> heap_left;
    priority_queue<int,vector<int>, greater<int>> heap_right;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if((heap_left.size()+heap_right.size())%2==0){
            if(heap_right.size()&&heap_right.top()<num){
                int t = heap_right.top();
                heap_right.pop();
                heap_right.push(num);
                num = t;
            }
            heap_left.push(num);
        } else{
            if(heap_left.size()&&heap_left.top()>num){
                int t = heap_left.top();
                heap_left.pop();
                heap_left.push(num);
                num = t;
            }
            heap_right.push(num);
        }
    }
    
    double findMedian() {
        if((heap_left.size()+heap_right.size())%2==0)
            return heap_left.top()*0.5+heap_right.top()*0.5;
        else
            return heap_left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */