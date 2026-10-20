class Solution {
public:
    int countSubstrings(string s) {
        int palindromes = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size()&& s[l]==s[r]) {

                    palindromes++;
                l--;
                r++;
            }
            r = 1 + (l=i);
            while (l >= 0 && r < s.size()&&s[l]==s[r]) {
                    palindromes++;
            
                l--;
                r++;
            }
        }
        return palindromes;
    }
};
