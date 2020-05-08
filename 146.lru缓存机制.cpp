/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (46.68%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 104.8K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2  缓存容量  );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */
#include <array>
#include <map>

using namespace std;

// @lc code=start
class LRUCache {

    struct DLinkedNode{
        int key;
        int value;

        DLinkedNode* prev;
        DLinkedNode* next;

        DLinkedNode()=default;

        DLinkedNode(int key, int value):key(key),value(value),prev(nullptr),next(nullptr){}
        DLinkedNode(int key, int value, DLinkedNode* prev, DLinkedNode* next):key(key),value(value),prev(prev), next(next){}
    };

private:
    map<int, DLinkedNode> cache;
    int capacity;
    DLinkedNode head;
    DLinkedNode tail;
    

public:
    LRUCache(int capacity):capacity(capacity),head(-1,-1),tail(-1,-1) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            cache[key].prev->next = cache[key].next;
            cache[key].next->prev = cache[key].prev;

            cache[key].prev = &head;
            cache[key].next = head.next;

            head.next->prev = &cache[key];
            head.next = &cache[key];
            return cache[key].value;
        }else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)==cache.end()){
            if(cache.size()==capacity){
                int delete_key = tail.prev->key;
                tail.prev->prev->next = &tail;
                tail.prev = tail.prev->prev;

                cache.erase(delete_key);
            }
            cache[key] = DLinkedNode(key, value, &head, head.next);
        }else{
            cache[key].value = value;

            cache[key].prev->next = cache[key].next;
            cache[key].next->prev = cache[key].prev;

            cache[key].prev = &head;
            cache[key].next = head.next;
        }
        head.next->prev = &cache[key];
        head.next = &cache[key];
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

