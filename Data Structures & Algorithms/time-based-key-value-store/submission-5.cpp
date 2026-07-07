class TimeMap {
unordered_map<string, vector<pair<int, string>>> time_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        const auto& values = time_map[key];
        int left = 0, right = values.size()-1;
        pair<int, string> result = {0, ""};
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (values[mid].first <= timestamp) {
            left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return (left > 0) ? values[left - 1].second : "";
    }
};
