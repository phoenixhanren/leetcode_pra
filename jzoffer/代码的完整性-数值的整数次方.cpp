#include <math>

using namespace std;

class Solution {
public:
    double PowerBF(double base, int exponent) {
        if (base == 0.0)
            return 0;
        if (exponent == 0.0)
            return 1;
        int exp_temp = exponent;
        //int nag_flag = false;
        if (exponent < 0)
        {
            exp_temp = abs(exponent);
            //nag_flag = true;
        }
        double ans = base;
        for (int i = 1; i < exp_temp; ++i)
        {
            ans *= base;
        }
        if (exp_temp != exponent)
        {
            return 1.0 / ans;
        }
        else
        {
            return ans;
        }
    }
    double PowerHHD(double base, int exponent) {
        if (base == 0.0)
            return 0;
        if (exponent == 0.0)
            return 1.0;
        int exp_temp = exponent < 0 ? abs(exponent) : exponent;
        int exp_curr = 1;
        int ans = base;

        for (; exp_curr * 2 <= exp_temp; exp_curr *= 2)
        {
            ans *= ans;
        }

        for (; exp_curr < exp_temp; ++exp_curr)
        {
            ans *= base;
        }

        return exp_temp == exponent ? ans : (1.0 / ans);
    }
    double Power(double base, int exponent) {
        if (abs(base - 0.0) < 0.0000001)
            return 0.0;
        if (exponent == 0)
            return 1;

        int exp_temp = exponent < 0 ? abs(exponent) : exponent;
        double result = PRec(base, exp_temp);
        
        return exp_temp == exponent ? result : (1.0 / result);
    }

    double PRec(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;
        
        double result = PRec(base, exponent >> 1);
        result *= result;
        if (exponent & 0x1 == 1)
            result *= base;
        return result;
    }

};