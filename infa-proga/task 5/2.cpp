#include "stack.cpp"
#include <iostream>


int main()
{
    int n;
    std::cout << "n = "; std::cin >> n;
    stack<int>* h = nullptr;
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        push(h, x);
    }
    reverse(h);


    int mi = min(h);
    int ma = max(h);
    int index_min_1 = -1; int index_min_2 = -1;
    stack<int>* h1 = nullptr;
    int i = 0;
    while (h)
    {
        if (h->inf == mi)
        {
            if (index_min_1 == -1)
            {
                index_min_1 = i;
            }
            else
            {
                index_min_2 = i;
            }
        }
        push(h1, pop(h));
        i++;
    }
    reverse(h1);
    h = h1;
    if (index_min_2 == -1)
    {
        index_min_2 = index_min_1;
    }
    insert(h, ma, index_min_1);
    insert(h, ma, index_min_2 + 1);


    while (h)
    {
        std::cout << pop(h) << " ";
    }
    std::cout << "\n";
    return 0;
}
