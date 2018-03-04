#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
/*
int main()
{
    vector<int> v;
    int n;
    cin >> n;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v.push_back(temp);
        reverse(v.begin(), v.end());
    }

    cout << v[0];
    for (int i = 1; i < n; ++i)
    {
        cout << " " << v[i];
    }
    cout << endl;

    return 0;

}*/



int main()
{
    int n;
    cin >> n;
    int temp;
    cin >> temp;

    list<int> l;
    l.push_back(temp);

    int flag = true;

    for (int i = 1; i < n; ++i)
    {
        cin >> temp;
        if (flag)
        {           
            l.push_front(temp);
            flag = false;
        }
        else
        {
            l.push_back(temp);
            flag = true;
        }
    }

    if (flag == false)
    {
        auto iter = l.begin();
        cout << *iter++;
        for (; iter != l.end(); ++iter)
        {
            cout << " " << *iter;
        }
        cout << endl;
       // return 0;
    }
    else
    {
        auto iter = l.rbegin();
        cout << *iter++;
        for (; iter != l.rend(); ++iter)
        {
            cout << " " << *iter;
        }
        cout << endl;
        //return 0;
    }

    return 0;

}