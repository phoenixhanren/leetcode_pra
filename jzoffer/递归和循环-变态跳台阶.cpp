class Solution {
public:
    int jumpFloorII(int number) {
        int * mem = new int[number + 1];
        for (int i = 0; i <= number; ++i)
        {
            mem[i] = -1;
        }
        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            int temp = 0;
            for (int j = 0; j < i; ++j)
            {
                temp += mem[j];
            }
            mem[i] = temp;
        }
        int ans = mem[number];
        delete [] mem;
        return ans;
    }
};