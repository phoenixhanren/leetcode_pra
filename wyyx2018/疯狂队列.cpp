#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    list<int> q;
    q.push_back(nums[n - 1]);
    int left = 0;
    int right = n - 2;
    int flag = true;
    int m = n - 1;
    while (q.size() < n && m > 0)
    {
        if (flag)
        {
            if (m > 0)
            {
                q.push_front(nums[left++]);
                --m;
            }
            if (m > 0)
            {
                q.push_back(nums[left++]);
                --m;
            }

        }
        else
        {
            if (m > 0)
            {
                q.push_front(nums[right--]);
                --m;
            }
            if (m > 0)
            {
                q.push_back(nums[right--]);
                --m;
            }
                           
        }
        flag = !flag;
    }
    auto first = q.begin();
    auto last = q.rbegin();
    auto last_two = ++q.rbegin();
    if (last_two != q.rend())
    {
        int last_value = abs(*last_two - *last);
        int first_value = abs(*last - *first);
        if (first_value > last_value)
        {
            q.push_front(*q.rbegin());
            q.pop_back();
        }
    }


    auto iter = q.begin();
    auto iter_left = ++q.begin();
    int count = 0;
    for (; iter_left != q.end(); ++iter, ++iter_left)
    {
        count += abs(*iter_left - *iter);
    }
    cout << count << endl;
    return 0;

}