#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> d;

    for (long long i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            d.push_back(i);
        }
        else
        {
            if (n % i == 0)
            {
                d.push_back(i);
                d.push_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    if (k > size(d))
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << d[k - 1] << '\n';
    }
    return 0;
}
