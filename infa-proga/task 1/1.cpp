#include <algorithm>
#include <iostream>
#include <vector>


void ans(std::vector<int>& vec)
{
    int m = *std::max_element(vec.begin(), vec.end());
    std::cout << "max element = " << m << "\n";
    std::cout << "count max element: " << std::count(vec.begin(), vec.end(), m) << "\n";
}


int main()
{
    int n;
    std::cout << "vector length: ";
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto& x: vec)
    {
        std::cin >> x;
    }
    ans(vec);
    return 0;
}
