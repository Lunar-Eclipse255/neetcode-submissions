class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0, resIdx = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l]==s[r]) {
                if (r-l+1 > maxlen) {
                    resIdx = l;
                    maxlen = r - l + 1;
                }
                l--;
                r++;
            }
            r = 1 + (l = i);
            while (l >= 0 && r < s.size() && s[l]==s[r]) {
                if (r-l+1 > maxlen) {
                    resIdx = l;
                    maxlen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(resIdx, maxlen);
    }
};
