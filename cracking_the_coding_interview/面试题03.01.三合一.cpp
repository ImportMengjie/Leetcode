/*
三合一。描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

示例1:

 输入：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 输出：
[null, null, null, 1, -1, -1, true]
说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
示例2:

 输入：
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, -1, -1]

提示：

0 <= stackNum <= 2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/three-in-one-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

class TripleInOne {
private:
    std::vector<int>  arr;
    int stackSize;
    int stack_nums = 3;
public:
    TripleInOne(int stackSize):stackSize(stackSize) {
        arr.resize(stack_nums*(stackSize+1), 0);
    }
    
    void push(int stackNum, int value) {
        assert(stackNum<stack_nums);
        if(arr[stackNum]<stackSize){
            arr[stack_nums+stackNum*stackSize+arr[stackNum]++] = value;
        }
    }
    
    int pop(int stackNum) {
        if(arr[stackNum]>0){
            arr[stackNum]--;
            return arr[stack_nums+stackNum*stackSize+arr[stackNum]];
        }
        return -1;
    }
    
    int peek(int stackNum) {
        if(arr[stackNum]>0){
            return arr[stack_nums+stackNum*stackSize+arr[stackNum]-1];
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        return arr[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */