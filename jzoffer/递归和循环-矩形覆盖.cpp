class Solution {
public:
    int rectCover(int number) {
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        int left = 1;
        int right = 1;
        for (int i = 2; i <= number; ++i)
        {
            int temp = left + right;
            left = right;
            right = temp;
        }
        return right;
    }
};