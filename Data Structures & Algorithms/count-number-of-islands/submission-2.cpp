class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i,j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        grid[r][c]='0';
        for (int i = 0; i < 4; ++i) {
            dfs(r + directions[i][0], c + directions[i][1], grid);
        }
    }
};
