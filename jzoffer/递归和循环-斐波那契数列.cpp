class Solution {
public:

    Solution() {
        for (int i = 0; i < 40; ++i)
        {
            mem[i] = -1;
        }
        mem[0] = 0;
        mem[1] = 1;
    }

    int FibonacciRec(int n) {
        if (mem[n] == -1)
        {
            mem[n] = FibonacciRec(n - 1) + FibonacciRec(n - 2);
            return mem[n];
        }
        else
        {
            return mem[n];
        }
    }

    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int left = 0;
        int right = 1;
        for (int i = 2; i <= n; ++i)
        {
            int temp = left + right;
            left = right;
            right = temp;
        }
        return right;
    }
private:
    int mem[40];
};