class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.reserve(n + 1);
        for (int i = 0; i <= n; ++i) {
            int res_bits = 0;
            int copy = i;
            while(copy) {
                copy &= copy - 1;
                ++res_bits;
            }
            res.push_back(res_bits);
        }
        return res;
    }
};
