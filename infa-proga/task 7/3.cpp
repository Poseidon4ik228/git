#include "tree.cpp"
#include <iostream>
#include <vector>
#include <cmath>

void lvl(tree* tr, int k, int l, std::vector<int>& leaves)
{
    if (!tr || l > k)
    {
        return;
    }

    if (l == k)
    {
        if (tr->left == nullptr && tr->right == nullptr)
        {
            leaves.push_back(tr->inf);
        }
        return;
    }

    lvl(tr->left, k, l + 1, leaves);
    lvl(tr->right, k, l + 1, leaves);
}

int main()
{
    int n, k;
    std::cout << "n = "; std::cin >> n;
    std::cout << "k = "; std::cin >> k;

    tree* tr = nullptr;
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        insert(tr, x);
    }

    inorder(tr);
    std::cout << "\n";

    std::vector<int> leaves;
    lvl(tr, k, 0, leaves);

    if (!leaves.empty())
    {
        double sum = 0;
        for (int val : leaves)
        {
            sum += val;
        }
        double mean = sum / leaves.size();

        int sr = leaves[0];
        double min_diff = std::abs(leaves[0] - mean);

        for (int val : leaves)
        {
            double diff = std::abs(val - mean);
            if (diff < min_diff)
            {
                min_diff = diff;
                sr = val;
            }
        }

        tree* target = find(tr, sr);
        if (target && target->parent && target->parent->parent)
        {
            Delete(tr, target->parent->parent);
        }
    }
    else
    {
        std::cout << "Листьев на уровне " << k << " не найдено\n";
    }

    inorder(tr);
    std::cout << "\n";

    delete_tree(tr);

    return 0;
}
/*
test1:
4
2
50 30 70 20
ans: 20 30 70


test2:
7
2
50 30 70 20 40 60 80
ans: 20 30 40 60 70 80


test3:
9
3
100 50 150 30 70 120 180 20 190
ans: 20 30 70 100 120 150 180 190


test4:
4
3
10 20 30 40
ans: 10 30 40
 */
