class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::pair<int, int> counter= {-1, 0};
        for (int num : nums){
            if (counter.second==0){
                counter={num,1};
            }
            else if (counter.first == num){
                counter.second++;
            }
            else{
                counter.second--;
            }
        }
        return counter.first;
    }
};