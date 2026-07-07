class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;

        while (left <= right) {
            long time = 0;
            int mid = left + (right - left)/2;
            for (int element: piles) {
               time += ceil(static_cast<double>(element) / mid);
            }
            if (time <= h) {
                res = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return res;
    }
};
