class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target(26, 0);
        vector<int> window(26, 0);
        if (s1.length() > s2.length()) {
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            target[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        if (target == window) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            window[s2[i] - 'a']++;
            window[s2[i-s1.size()] - 'a']--;
            if (target == window) {
                return true;
            }
        }
        return false;
    }
};
