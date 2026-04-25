class TimeMap {
    unordered_map<string, map<int, string>> time_map; // key -> {time -> value}
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].emplace(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if (it == time_map.end())
            return "";
        const auto &time_values = it->second;
        if (time_values.empty())
            return "";
        auto lo_it = time_values.upper_bound(timestamp);
        return lo_it == time_values.begin() ? "" : prev(lo_it)->second;
    }
};
