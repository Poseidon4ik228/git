#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>
#include <string>


int main()
{
    int n;
    std::cout << "length vector: "; std::cin >> n;
    std::cout << "vector: ";
    std::vector<int> vec(n);
    for (auto& x: vec)
    {
        std::cin >> x;
    }

    std::set<char> a;
    std::set<char> b;
    std::set<char> ans;

    for (auto x: vec)
    {
        std::string x1 = std::to_string(x);
        for (char i: x1)
        {
            b.insert(i);
        }
        if (x1.size() == 3)
        {
            a.insert(char(x1[0]));
            a.insert(char(x1[1]));
            a.insert(char(x1[2]));
        }
    }

    std::set_difference(b.begin(), b.end(), a.begin(), a.end(), std::inserter(ans, ans.begin()));


    std::cout << "answer: ";
    for (auto& i: ans)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}
