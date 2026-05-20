#include "queue.cpp"
#include <iostream>


int main()
{
    int n;
    std::cout << "n = "; std::cin >> n;
    int x; queue* h = nullptr; queue* t = nullptr;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        push(h, t, x);
    }


    queue* temp_h = nullptr;
    queue* temp_t = nullptr;
    while (h)
    {
        if (h->inf % 2 == 0)
        {
            while (temp_h)
            {
                push(h, t, pop(temp_h, temp_t));
            }
            break;
        }

        else
        {
            push(temp_h, temp_t, pop(h, t));
        }
    }


    while (temp_h)
    {
        push(h, t, pop(temp_h, temp_t));
    }


    while(h)
    {
        std::cout << pop(h, t) << " ";
    }
    std::cout << "\n";
    return 0;
}
