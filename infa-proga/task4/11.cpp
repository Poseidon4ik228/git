#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


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


void bubble_sort (std::vector<int>& x, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (x[j] >= x[j + 1])
            {
                std::swap(x[j], x[j + 1]);
            }
        }
    }
}


int main()
{
    int n;
    in >> n;
    std::vector<std::vector<int>> x;
    x = inFile(n);
    for (int s = 0; s < 2 * n - 2; s++)
    {
        std::vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            int j = s - i;
            if (j >= 0 && j < n)
            {
                temp.push_back(x[i][j]);
            }
        }

        bubble_sort(temp, temp.size());

        int temp_index = 0;
        for (int i = 0; i < n; i++)
        {
            int j = s - i;
            if (j >= 0 && j < n)
            {
                x[i][s - i] = temp[temp_index];
                temp_index++;
            }
        }
    }
    print(x, n);
    return 0;
}
