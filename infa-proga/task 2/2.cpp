#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>


int main()
{
    int k;
    std::cout << "k = "; std::cin >> k;

    std::ifstream file("2.txt");
    std::string str;
    std::getline(file, str);
    std::map<std::string, int> ans;
    int r = 0, l = 0;
    for (; r < str.size(); r++) {
        if (isdigit(str[r]) || str[r] == ' ') {
            if (r > l)
            {
                ans[str.substr(l, r - l)] += 1;
            }
            l = r + 1;
        }
    }
    if (r > l)
    {
        ans[str.substr(l, r - l)] += 1;
    }


    std::set<int> coun;
    for (int i = 0; i < k; i++)
    {
        for (auto& x: ans)
        {
            coun.insert(x.second);
        }
    }
    std::vector<int> coun1(coun.begin(), coun.end());
    int fl = 0;
    for (int i = 0;; i++)
    {
        for (auto& x: ans)
        {
            if (k == 0)
            {
                fl = 1;
                break;
            }
            if (x.second == coun1[i])
            {
                std::cout << x.first << " " << x.second << "\n";
                k--;
            }
        }
        if (fl == 1)
        {
            break;
        }
    }

    return 0;
}
