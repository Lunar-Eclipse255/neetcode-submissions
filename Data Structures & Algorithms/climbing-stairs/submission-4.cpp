class Solution {
public:
    int climbStairs(int n) {
        int s_one = 1;
        int s_two = 1;
        for (int i = 0; i <n; ++i) {
            int temp = s_one;
            s_one = s_one + s_two;
            s_two = temp;
        }
        return s_two;
    }
};
