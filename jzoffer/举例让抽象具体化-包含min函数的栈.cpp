#include <stack>
#include <math>
using namespace std;

class Solution {
public:
    void push(int value) {
        val_stack.push(value);
        if (min_stack.size() == 0)
            min_stack.push(value);
        min_stack.push(std::min(min_stack.top(), value));
    }
    void pop() {
        val_stack.pop();
        min_stack.pop();
    }
    int top() {
        return val_stack.top();
    }
    int min() {
        return min_stack.top();
    }
private:
    stack<int> val_stack;
    stack<int> min_stack;
};