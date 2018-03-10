class Temp {
public:
    Temp() {
        ++N; 
        sum += N;
    }

    static void reset() {
        N = 0;
        sum = 0;
    }

    static int getSum() {
        return sum;
    }

private:

    static unsigned int N;
    static unsigned int sum;

};

unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Temp::reset();
        Temp * t = new Temp[n];
        int ans = Temp::getSum();
        delete [] t;
        return ans;
    }
};

