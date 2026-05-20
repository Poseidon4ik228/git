#include "list.cpp"
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

    list* temp = h;
    int fl = 0;
    while (temp && fl < 2)
    {
        if (temp->inf % 2 != 0)
        {
            del_node(h, t, temp);
            reverse(h, t);
            temp = h;
            fl += 1;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (fl == 1)
    {
        reverse(h, t);
    }
    print(h, t);
}
