/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class MedianFinder {
private:
    priority_queue<int,vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty()||num<=left.top()) {
            left.push(num);
            if(left.size()-right.size()>1) {
                right.push(left.top());
                left.pop();
            }
        } else{
            right.push(num);
            if(right.size()-left.size()>0) {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if((left.size()+right.size())%2==0) 
            return left.top()/2.0+right.top()/2.0;
        else
            return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

