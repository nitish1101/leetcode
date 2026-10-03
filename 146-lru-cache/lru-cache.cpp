#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

// LeetCode 146: LRU Cache
// Doubly linked list keeps entries in recency order (front = most recent);
// a hash map points each key at its list node. get and put are O(1).
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }
        if ((int)items.size() == cap) {
            pos.erase(items.back().first);
            items.pop_back();
        }
        items.emplace_front(key, value);
        pos[key] = items.begin();
    }

private:
    int cap;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> pos;
};
