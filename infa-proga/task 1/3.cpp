#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <algorithm>


int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;


    std::vector<int> vec(n);
    std::iota(vec.begin(), vec.end(), 0);
    std::function<int(int)> power = [](int a) { return 1 << a; };
    std::transform(vec.begin(), vec.end(), vec.begin(), power
    );


    for (auto x : vec) {
        std::cout << x << ' ';
    }
    std::cout << "\n";

    return 0;
}
