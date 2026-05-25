#include "tree.cpp"
#include <iostream>


int Sum(tree* tr)
{
    if (!tr)
    {
        return 0;
    }
    if (tr->right == nullptr && tr->left == nullptr)
    {
        return tr->inf;
    }
    return Sum(tr->left) + Sum(tr->right);
}


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
    inorder(tr); std::cout << "\n";

    std::cout << Sum(tr) << "\n";

    return 0;
}

/*
test1:
7
5 3 7 2 4 6 8
ans: 20


test2:
5
1 2 3 4 5
ans: 5


test3:
7
10 5 15 2 12 20 1
ans: 33


test4:
1
42
ans: 42


test5:
6
8 3 10 3 10 1
ans: 11
 */
