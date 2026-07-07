class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> anagrams;
        for (string word : strs) {
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(word);
        }
        for (auto& element : map) {
            anagrams.push_back(element.second);
        }
        return anagrams;
    }
};
