#include "list.cpp"
#include <cmath>
#include <iostream>


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

    int s = t->inf;
    list* temp = t->prev;
    double sr = 0;
    int k = 1;
    while (temp)
    {
        k += 1;
        s += temp->inf;
        sr = s * 1.0 / k;
        if (temp->inf > sr)
        {
            list* temp1 = temp;
            temp = temp->prev;
            s -= temp1->inf;
            k--;
            del_node(h, t, temp1);
        }
        else
        {
            temp = temp->prev;
        }
    }
    print(h, t);
}
