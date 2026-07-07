class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> result(n);

        int pref = 1;
        int suf = 1;

        for (int i = 0; i < n; i++) {
            prefix[i] = pref;
            pref *= nums[i];

            suffix[n - 1 - i] = suf;
            suf *= nums[n - 1 - i];
        }

        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};
