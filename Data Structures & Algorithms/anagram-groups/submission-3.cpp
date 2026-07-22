class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagrams[sorted_str].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& item: anagrams) {
            result.push_back(item.second);
        }
        return result;
    }
};
