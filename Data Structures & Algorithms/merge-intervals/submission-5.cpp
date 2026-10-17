class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> interval = intervals[0];;
        if (intervals.empty()) {
            return {};
        }
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0]<=interval[1]) {
                interval[1] = max(intervals[i][1], interval[1]);
            }
            else {
                res.push_back(interval);
                interval=intervals[i];
            }
        }
        res.push_back(interval);

        return res;
    }
};
