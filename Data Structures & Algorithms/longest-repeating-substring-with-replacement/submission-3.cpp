class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int sol = 0;
        int l = 0;
        int max_f = 0;
        for (int r = 0; r < s.size(); r++) {
            max_f = max(max_f, ++count[s[r]]);
            while (r - l +1 - max_f > k) {
                count[s[l]]--;
                l++;
            }
            sol = max (sol, r - l +1);
        }
        return sol;
    }
};
