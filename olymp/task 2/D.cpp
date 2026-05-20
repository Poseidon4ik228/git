#include <iostream>

using namespace std;


int main()
{
    long long s, n;
    cin >> s >> n;
    for (long long d = 1;;d++)
    {
        if (2 * s - n * d * (n - 1) < 0)
        {
            cout << -1 << '\n';
            return 0;
        }
        else if ((2 * s - n * d * (n - 1)) % (2 * n) == 0)
        {
            long long a1 = (2 * s - n * d * (n - 1)) / (2 * n);
            cout << a1 << ' ';
            for (int i = 2; i <= n; i++)
            {
                a1 += d;
                cout << a1 << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
}
