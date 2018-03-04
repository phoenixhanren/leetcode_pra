#include <cstring>
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 1 || numbers == nullptr)
        {
            duplication = nullptr;
            return false;
        }

        int * hash_map = new int [length];
        memset(hash_map, 0, sizeof(int) * length);

        for (int i = 0; i < length; ++i)
        {
            if (hash_map[numbers[i]] != 0)
            {
                *duplication  = numbers[i];
                return true;
            }
            hash_map[numbers[i]] += 1;
        }
        duplication = nullptr;
        return false;
    }
};