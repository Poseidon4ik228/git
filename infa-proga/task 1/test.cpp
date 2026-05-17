#include <iostream>


int main()
{
    auto func = [](int x) {return x % 2 == 0;};
    int x;
    std::cin >> x;
    std::cout << func(x) << "\n";
    return 0;
}
