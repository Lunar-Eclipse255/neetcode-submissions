class MinStack {
public:
    std::stack<int> int_stack;
    std::stack<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        int_stack.push(val);
        min_stack.push(min(val, min_stack.empty() ? val : min_stack.top()));
    }
    
    void pop() {
        int_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return int_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
