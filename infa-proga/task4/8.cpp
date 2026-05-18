#include <iostream>
#include <fstream>
#include <vector>


std::ifstream in("input1.txt");
std::ofstream out("output1.txt");


std::vector<std::vector<int>> inFile(int n)
{
    std::vector<std::vector<int>> x(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int elem;
            in >> elem;
            x[i].push_back(elem);
        }
    }
    return x;
}


void print(std::vector<std::vector<int>>& x, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out << x[i][j] << " ";
        }
        out << "\n";
    }
}


void merge (std::vector<int>& x, int left, int mid, int right, int flag)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = x[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = x[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j] && flag == 1)
        {
            x[k] = L[i];
            i++;
        }
        else if (flag == 1)
        {
            x[k] = R[j];
            j++;
        }
        else if (L[i] >= R[j] && flag == 0)
        {
            x[k] = R[j];
            j++;
        }
        else if (flag == 0)
        {
            x[k] = L[i];
            i++;
        }
        k++;
    }
    while (i < n1)
    {
        x[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        x[k] = R[j];
        k++;
        j++;
    }
}


void merge_sort(std::vector<int>& x, int left, int right, int flag)
{
    if (left >= right)
    {
        return;
    }
    int mid = (right + left) / 2;
    merge_sort(x, left, mid, flag);
    merge_sort(x, mid + 1, right, flag);
    merge(x, left, mid, right, flag);
}


int main()
{
    int n;
    in >> n;
    std::vector<std::vector<int>> x;
    x = inFile(n);
    for (int j = 0; j < n; j++)
    {
        if (j % 3 == 2)
        {
            merge_sort(x[j], 0, n - 1, 1);
        }
        else
        {
            merge_sort(x[j], 0, n - 1, 0);
        }
    }

    print(x, n);
    return 0;
}
