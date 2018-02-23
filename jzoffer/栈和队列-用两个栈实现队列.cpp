#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (stack1.empty() == false)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret_val = stack2.top();
        stack2.pop();
        while (stack2.empty() == false)
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ret_val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};