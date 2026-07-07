class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0;
        int max_val = 0;
        for (char c : s){
            while (chars.find(c) != chars.end()) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(c);
            max_val = max((int)chars.size(), max_val);
        }
        return max_val;
    }
};