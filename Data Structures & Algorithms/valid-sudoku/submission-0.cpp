class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& row : board) {
            unordered_set<char> row_set; 
            for (auto& element : row) {
                if (element == '.') {}
                else {
                    if (row_set.find(element) != row_set.end()) {
                        return false;
                    }
                    row_set.insert(element);
                }
            }
        }
        for (int i = 0; i<9; i++) {
            unordered_set<char> col; 
            for (int j = 0; j<9; j++) {
                char element = board.at(j).at(i);
                if (element == '.') {}
                else {
                    if (col.find(element) != col.end()) {
                        return false;
                    }
                    col.insert(element);
                }
            }
        }
        for (int box = 0; box<9; box++){
            unordered_set<char> seen; 
            for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++){
                    char element = board.at((box / 3) * 3 + i).at((box % 3) * 3 + j);
                    if (element == '.') {
                        continue;
                    }
                    if (seen.find(element) != seen.end()) {
                        return false;
                    }
                    seen.insert(element);

                }
            }
        }
        return true;
        
    }
};