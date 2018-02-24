class Solution {
public:
     int  NumberOf1BF(int n) {
          int count = 0;
          int mask = 1;
          while (mask != 0)
          {
              if ((n & mask) != 0)
                ++count;
              mask <<= 1;
          }   
          return count;    
     }
     int NumberOf1(int n) {
         int count = 0;
         while (n != 0)
         {
             ++count;
             n = n & (n - 1);
         }
         return count;
     }
};