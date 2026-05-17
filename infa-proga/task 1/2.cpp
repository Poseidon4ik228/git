#include <iostream>
#include <vector>
#include <algorithm>


void print(std::vector<int>* vec)
{
    for (size_t i = 0; i < (*vec).size(); i++)
    {
        std::cout << (*vec)[i] << ' ';
    }
    std::cout << "\n";
}


int main()
{
    int n;
    std::cout << "vector length: ";
    std::cin >> n;
    std::cout << "vector: ";
    std::vector<int> vec(n);
    for (auto& x: vec)
    {
        std::cin >> x;
    }


    auto func = [](int x) {return x % 2 != 0;};
    auto it = remove_if(vec.begin(), vec.end(), func);
    vec.erase(it, vec.end());
    print(&vec);


    auto min_el = std::min_element(vec.begin(), vec.end());
    std::rotate(vec.begin(), min_el, vec.end());
    print(&vec);


    std::sort(vec.begin(), vec.end());
    print(&vec);


    int new_el;
    std::cout << "new element = ";
    std::cin >> new_el;
    auto func_2 = [new_el](int x){return x >=new_el;};
    auto l = std::find_if(vec.begin(), vec.end(), func_2);
    if (l == vec.end())
        l = vec.begin();
    vec.insert(l, new_el);
    print(&vec);


    return 0;
}
