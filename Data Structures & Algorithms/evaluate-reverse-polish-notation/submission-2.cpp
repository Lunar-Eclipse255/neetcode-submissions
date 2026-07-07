class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;
        int sum, sub, mult_hold, div_hold;
        for (const auto & s : tokens) {
            if (s.length() > 1 || isdigit(s[0])) {
                operands.push(stoi(s));
                continue;
            }
            switch (s[0]){
                case '+':
                    sum = 0;
                    sum += operands.top();
                    operands.pop();
                    sum += operands.top();
                    operands.pop();
                    operands.push(sum);
                    break;
                case '-':
                    sub = 0;
                    sub += -operands.top();
                    operands.pop();
                    sub += operands.top();
                    operands.pop();
                    operands.push(sub);
                    break;
                case '*':
                    mult_hold = operands.top();
                    operands.pop();
                    mult_hold *= operands.top();
                    operands.pop();
                    operands.push(mult_hold);
                    break;
                case '/':
                    div_hold = operands.top();
                    operands.pop();
                    div_hold = operands.top() / div_hold;
                    operands.pop();
                    operands.push(div_hold);
                    break;
                
            }
        }
        return operands.top();
    }
};