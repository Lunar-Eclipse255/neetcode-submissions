class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }
        unordered_map<char, int> countT, window;
        for (char c : t){
            countT[c]++;
        }
        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for (int i = 0; i<s.length(); ++i) {
            window[s[i]]++;
            if (countT.count(s[i]) && window[s[i]]==countT[s[i]]){
                have++;
            }
            while (have == need){
                if((i-l+1)<resLen){
                    resLen= i-l+1;
                    res = {l, i};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }

        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
