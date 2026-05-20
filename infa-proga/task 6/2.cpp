#include "list.cpp"
#include <cmath>
#include <iostream>


int composite(int x)
{
    if (x <= 3)
    {
        return 0;
    }
    for (int i = 2; i < std::sqrt(x) + 1; i++)
    {
        if (x % i == 0)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int n;
    std::cout << "n = "; std::cin >> n;
    list* h = nullptr; list* t = nullptr;
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        push(h, t, x);
    }

    list* temp = h;
    if (!composite(h->inf))
    {
        int i = 0;
        temp->prev = t;
        t->next = temp;
        while (i < n)
        {
            if (composite(temp->inf))
            {
                break;
            }
            temp = temp->next;
            i++;
        }
        t = temp->prev;
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        h = temp;
    }
    print(h, t);
}
