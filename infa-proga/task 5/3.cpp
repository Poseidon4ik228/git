#include "queue.cpp"
#include <iostream>


int main()
{
    int n;
    std::cout << "n = "; std::cin >> n;
    queue* h = nullptr;
    queue* t = nullptr;
    int last_dig;
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        push(h, t, x);
    }
    last_dig = t->inf;
    int max_element = max(h);


    for (int i = 0; i < n; i++)
    {
        int temp = pop(h, t);
        push(h, t, temp);
        if (temp == last_dig)
        {
            push(h, t, max_element);
        }
    }


    while (h)
    {
        std::cout << pop(h, t) << " ";
    }
    std::cout << "\n";
    return 0;
}
