/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (42.45%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 53.5K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
 * 
 * 实现 LFUCache 类：
 * 
 * 
 * LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
 * void put(int key, int value) -
 * 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除
 * 最久未使用 的键。
 * 
 * 
 * 注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。
 * 
 * 为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
 * 
 * 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put
 * 操作，使用计数器的值将会递增。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * 输出：
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * 解释：
 * // cnt(x) = 键 x 的使用计数
 * // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
 * LFUCache lFUCache = new LFUCache(2);
 * lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lFUCache.get(1);      // 返回 1
 * ⁠                     // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
 * ⁠                     // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lFUCache.get(2);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * ⁠                     // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
 * ⁠                     // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lFUCache.get(1);      // 返回 -1（未找到）
 * lFUCache.get(3);      // 返回 3
 * ⁠                     // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lFUCache.get(4);      // 返回 4
 * ⁠                     // cache=[3,4], cnt(4)=2, cnt(3)=3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 最多调用 10^5 次 get 和 put 方法
 * 
 * 
 * 
 * 
 * 进阶：你可以为这两种操作设计时间复杂度为 O(1) 的实现吗？
 * 
 */
#include <list>
#include <unordered_map>

using namespace std;

// @lc code=start
class LFUCache {
private:

    struct Node {
        int freq, key, value;
        Node(int freq, int key, int value):freq(freq), key(key), value(value){}
    };
    
    unordered_map<int, list<Node>::iterator> value_map;
    unordered_map<int, list<Node>> freq_map;

    int capacity;
    int min_freq;


public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 1;
    }
    
    int get(int key) {
        if(value_map.count(key)==0) return -1;
        int freq = value_map[key]->freq;
        int value = value_map[key]->value;
        freq_map[freq].erase(value_map[key]);
        if(freq_map[freq].empty()){
            freq_map.erase(freq);
            if(freq==min_freq) min_freq++;
        }
        freq_map[freq+1].emplace_front(freq+1, key, value);
        value_map[key] = freq_map[freq+1].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(this->capacity==0) return;
        if(value_map.count(key)==0){
            if(this->capacity==value_map.size()){
                value_map.erase(freq_map[min_freq].back().key);
                freq_map[min_freq].pop_back();
                if(freq_map[min_freq].empty())
                    freq_map.erase(min_freq);
            }
            if(freq_map.count(1)==0)
                freq_map[1] = list<Node>();
            freq_map[1].emplace_front(1, key, value);
            min_freq = 1;
            value_map[freq_map[1].front().key] = freq_map[1].begin();
        } else{
            this->get(key);
            value_map[key]->value = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

