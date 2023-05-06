/*
堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。
当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，popAt 应返回 -1.

示例1:

 输入：
["StackOfPlates", "push", "push", "popAt", "pop", "pop"]
[[1], [1], [2], [1], [], []]
 输出：
[null, null, null, 2, 1, -1]
示例2:

 输入：
["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"]
[[2], [1], [2], [3], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, 3]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/stack-of-plates-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <deque>
#include <stack>

class StackOfPlates {
private:
    std::deque<std::stack<int>> stacks;
    int cap;
public:
    StackOfPlates(int cap):cap(cap) {
    }
    
    void push(int val) {
        if(cap==0) return;
        if(stacks.empty()||stacks.front().size()>=cap)
            stacks.emplace_front();
        stacks.front().push(val);
    }
    
    int pop() {
        if(stacks.empty()) return -1;
        int ret = stacks.front().top(); 
        stacks.front().pop();
        if(stacks.front().size()<=0)
            stacks.pop_front();
        return ret;
    }
    
    int popAt(int index) {
        index = stacks.size()-index - 1;
        if(stacks.size()>index){
            int ret = stacks[index].top();
            stacks[index].pop();
            if(stacks[index].size()==0)
                stacks.erase(stacks.begin()+index);
            return ret;
        }
        return -1;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */