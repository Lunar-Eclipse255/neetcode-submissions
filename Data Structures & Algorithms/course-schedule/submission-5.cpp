class Solution {
public:
    unordered_map<int, vector<int>> pre_map;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (const auto& prereq : prerequisites) {
            pre_map[prereq[0]].push_back(prereq[1]);
        }
        for (int c = 0; c < numCourses; ++c) {
            if (pre_map[c].empty()) {
                continue; 
            }

            stack<pair<int, int>> st;
            st.push({c, 0});
            visiting.insert(c);

            while (!st.empty()) {
                auto& [crs, i] = st.top();

                if (i < pre_map[crs].size()) {
                    int pre = pre_map[crs][i++];
                    if (visiting.count(pre)) {
                        return false;
                    }
                    if (!pre_map[pre].empty()) {
                        visiting.insert(pre);
                        st.push({pre, 0});
                    }
                }
                else {
                    visiting.erase(crs);
                    pre_map[crs].clear();
                    st.pop();
                }
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            return false;
        }
        if (pre_map[crs].empty()) {
            return true;
        }
        visiting.insert(crs);
        for (int pre : pre_map[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(crs);
        pre_map[crs].clear();
        return true;
    }
};
