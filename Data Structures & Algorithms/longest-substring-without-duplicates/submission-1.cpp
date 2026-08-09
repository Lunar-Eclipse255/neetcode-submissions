class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substrs;
        int len = 0;
        int maxl = 0;
        for (int i = 0; i<s.size(); i++) {
            if (substrs.find(s[i]) != substrs.end()) {
                len = max(substrs[s[i]]+1, len);
            }
            substrs[s[i]] = i;
            maxl = max(maxl, i - len + 1);
        }
        return maxl;
    }
};
