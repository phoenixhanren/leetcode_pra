#include <vector>
#include <math>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (n == 0)
            return 0;
        vector<int> mem(index);
        mem[0] = 1;
        //vector<int>::iterator mult2 = mem.begin();
        //vector<int>::iterator mult3 = mem.begin();
        //vector<int>::iterator mult5 = mem.begin();
        int mult2_index = 0;
        int mult3_index = 0;
        int mult5_index = 0;
        int curr = 1;
        for ( ;curr < index; ++curr)
        {
            int curr_min = min(min(mem[mult2_index] * 2, mem[mult3_index] * 3), mem[mult5_index] * 5);
            while (curr_min >= mem[mult2_index] * 2 && mult2_index < curr)
                ++mult2_index;
            while (curr_min >= mem[mult3_index] * 3 && mult3_index < curr)
                ++mult3_index;
            while (curr_min >= mem[mult5_index] * 5 && mult5_index < curr)
                ++mult5_index;
            mem[curr] = curr_min;
        }
        return mem[index - 1];
    }
};