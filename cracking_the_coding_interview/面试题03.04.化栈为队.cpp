/*
实现一个MyQueue类，该类用两个栈来实现一个队列。

示例：

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明：

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-queue-using-stacks-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stack>

using namespace std;

class MyQueue {
private:
    std::stack<int> inst;
    std::stack<int> outst;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inst.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outst.empty()){
            while(inst.size()){
                int top = inst.top();
                inst.pop();
                outst.push(top);
            }
        }
        int top = outst.top();
        outst.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(outst.empty()){
            while(inst.size()){
                int top = inst.top();
                inst.pop();
                outst.push(top);
            }
        }
        return outst.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inst.empty() && outst.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */