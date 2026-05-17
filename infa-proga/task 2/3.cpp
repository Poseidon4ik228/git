#include <iostream>
#include <string>
#include <set>


int main()
{
    std::string str;
    std::getline(std::cin, str);
    int l = 0, r = 0;
    std::set<std::string> ans;
    for (; r < str.size(); r++)
    {
        if (str[r] == '.')
        {
            l = r + 1;
        }
        else if (str[r] == '!' || str[r] == '?')
        {
            std::string x = str.substr(l, r - l);
            int l1 = 0, r1 = 0;
            for (; r1 < x.size(); r1++)
            {
                if (x[r1] == ' ')
                {
                    ans.insert(x.substr(l1, r1 - l1));
                    l1 = r1 + 1;
                }
            }
            if (l1 != r1)
            {
                ans.insert(x.substr(l1, r1 - l1));
            }
        }
    ans.erase("");
    }
    for (auto& x: ans)
    {
        std::cout << x << ' ';
    }
    std::cout << "\n";
    return 0;
}
