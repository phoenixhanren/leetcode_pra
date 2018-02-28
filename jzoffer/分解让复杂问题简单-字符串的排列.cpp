#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        n = str.length();
        if (n == 0)
            return all_str;
        get_str(str, 0);
        sort(all_str.begin(), all_str.end());
        return all_str;
    }

private:

    void get_str(string str, int index) {
        if (index == n)
        {
            all_str.push_back(str);
            return;
        }
        for (int i = index, j = index; j < n; ++j)
        {
            string temp_str = str;
            char temp = temp_str[i];
            if (temp == temp_str[j] && i != j)
                continue;
            temp_str[i] = temp_str[j];
            temp_str[j] = temp;
            get_str(temp_str, index + 1);
        }
        return;

    }
    int n;
    vector<string> all_str;
};