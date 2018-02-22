#include <string>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
         if (str == nullptr || length == 0)
            return;
        int str_len = strlen(str);
        int space_count = 0;
        for (int i = 0; i < str_len; ++i)
        {
            //if (isspace(str[i]))
            if (str[i] == ' ')
            {
                ++space_count;
            }
        }
        int tot_len = str_len + space_count * 2 + 1;
        if (tot_len > length)
            return;
        //char * temp_str = new char[str_len + 1];
        //strcpy(temp_str, str);
        int j = tot_len - 1;
        str[j--] = '\0';
        for (int i = str_len - 1; i >= 0 && j >= 0; --i)
        {
            //if (isspace(temp_str[i]))
            //if (isspace(str[i]))
            if (str[i] == ' ')
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%%';
            }
            else
            {
                //str[j--] = temp_str[i];
                str[j--] = str[i];
            }
        }
        return;
	}
};