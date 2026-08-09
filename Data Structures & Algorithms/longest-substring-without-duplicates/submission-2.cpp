class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substrs;
        int left = 0;
        int maxl = 0;
        for (int i = 0; i<s.size(); i++) {
            if (substrs.find(s[i]) != substrs.end()) {
                left = max(substrs[s[i]]+1, left);
            }
            substrs[s[i]] = i;
            maxl = max(maxl, i - left + 1);
        }
        return maxl;
    }
};
