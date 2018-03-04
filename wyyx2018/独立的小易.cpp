#include <iostream>

using namespace std;
/*
int main()
{
    int x, f, d, p;
    cin >> x >> f >> d >> p;

    int day_count = 0;
    while (d >= 0)
    {
        if (d < x || (d < x + p && f == 0))
        {
            break;
        }
        if (f != 0)
        {
            --f;
            d -= x;
        }
        else
        {
            d -= (x + p);
        }
        ++day_count;
    }
    cout << day_count << endl;
    return 0;
}*/

int main()
{
    int x, f, d, p;
    cin >> x >> f >> d >> p;

    int day_count = 0;

    if (f * x <= d)
    {
        day_count += f;
        f = 0;
        d -= (f * x);
    }
    else
    {
        cout << d / x << endl;
        return 0;
    }
    day_count += d / (x + p);
    cout << day_count << endl;
    return 0;
}