class Solution {
public:
    bool isValid(string s) {
        std::stack<char> char_stack;
        std::unordered_map<char, char> paran_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s) {
            if (paran_map.count(c)){
                if (!char_stack.empty() && char_stack.top()==paran_map[c]) {
                    char_stack.pop();
                }
                else {
                    return false;
                }
            }
            else{
                char_stack.push(c);
            }
        }
        return char_stack.empty();
    }
};
