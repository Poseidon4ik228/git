#include "tree.cpp"
#include <iostream>


int main()
{
    int n;
    std::cout << "n = "; std::cin >> n;
    tree* tr = nullptr;
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        insert(tr, x);
    }
    inorder(tr);
    std::cout << "\n";

    int a, b;
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    if (!find(tr, a))
    {
        std::cout << "path does not exist" << "\n";
    }
    else
    {
        tree* y = find(tr, a);
        if (!find(y, b))
        {
            std::cout << "path does not exist" << "\n";
        }
        else
        {
            int ans = 0;
            while (true)
            {
                if (b == y->inf)
                {
                    std::cout << "path = " << ans << "\n";
                    break;
                }
                else if (b > y->inf)
                {
                    y = y->right;
                }
                else if (b < y->inf)
                {
                    y = y->left;
                }
                ans += 1;
            }
        }
    }
    return 0;
}


/*
 *
 test1:
 7
 10 5 15 3 7 12 18
 10
 7
 path = 2


 test2:
 7
 10 5 15 3 7 12 18
 5
 12
 path does not exist


 test3:
 5
 50 30 70 20 40
 100
 30
 path does not exist


 test4:
 5
 50 30 70 20 40
 30
 30
 path = 0


 test5:
 5
 1 2 3 4 5
 2
 5
 path = 3
 *
 *
 */
