/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode-cn.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (38.52%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 54.4K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 * 
 * 实现 AllOne 类：
 * 
 * 
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 * 
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
 * 
 * 
 */
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class AllOne {
private:
    struct DNode{
        DNode* pre;
        DNode* next;
        unordered_set<string> keys;
        int count;

        DNode():pre(nullptr),next(nullptr),count(0){ }
        DNode(DNode* pre, DNode* next):pre(pre),next(next){ }
    };

    DNode* head;
    DNode* tail;

    unordered_map<string, DNode*> m;

public:
    AllOne() {
        head = new DNode();
        tail = new DNode();
        head->next = tail;
        tail->pre = head;
    }
    
    void inc(string key) {
        if(m.count(key)){
            DNode* n = m[key];
            if(n->pre->count==n->count+1){
                n->keys.erase(key);
                n->pre->keys.insert(key);
                m[key] = n->pre;
            }else{
                DNode* newNode = new DNode(n->pre,n);
                newNode->count = n->count+1;
                newNode->keys.insert(key);
                n->pre->next = newNode;
                n->pre = newNode;
                m[key] = newNode;
                n->keys.erase(key);
            }
            if(n->keys.size()==0){
                n->pre->next = n->next;
                n->next->pre= n->pre;
                delete n;
            }
        }else{
            if(tail->pre->count==1){
                tail->pre->keys.insert(key);
                m[key] = tail->pre;
            }
            else{
                DNode* newNode = new DNode(tail->pre,tail);
                newNode->count = 1;
                newNode->keys.insert(key);
                tail->pre->next = newNode;
                tail->pre = newNode;
                m[key] = newNode;
            }
        }
    }
    
    void dec(string key) {
        if(m.count(key)){
            DNode* n = m[key];
            if(n->count==1){
                n->keys.erase(key);
                m.erase(key);
            } else if(n->next->count==n->count-1){
                n->keys.erase(key);
                n->next->keys.insert(key);
                m[key] = n->next;
            } else{
                DNode* newNode = new DNode(n, n->next);
                newNode->count = n->count-1;
                newNode->keys.insert(key);
                n->next->pre = newNode;
                n->next = newNode;
                m[key] = newNode;
                n->keys.erase(key);
            }
            if(n->keys.size()==0){
                n->pre->next = n->next;
                n->next->pre= n->pre;
                delete n;
            }
        }
    }
    
    string getMaxKey() {
        if(head->next->count>0)
            return *head->next->keys.begin();
        else
            return "";
    }
    
    string getMinKey() {
        if(tail->pre->count>0)
            return *tail->pre->keys.begin();
        else
            return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

