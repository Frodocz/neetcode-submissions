class LRUCache {
    std::list<int> keys;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    int capacity_;
public:
    LRUCache(int capacity)
        : capacity_(capacity) {
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        auto [v, k_it] = it->second;
        keys.erase(k_it);
        keys.emplace_back(key);
        cache[key] = {v, std::prev(keys.end())};
        return v;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) // found existing one, update
        {
            auto [val, k_it] = it->second;
            keys.erase(k_it);
        }
        else if (keys.size() == capacity_) // not found, if full, remove lru 
        {
            int lru = keys.front();
            keys.pop_front();
            cache.erase(lru);
        }

        // insert new pair
        keys.emplace_back(key);
        cache[key] = {value, std::prev(keys.end())};
    }
};
