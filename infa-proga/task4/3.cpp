#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


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


void lsd (std::vector<std::vector<int>>& x, int n)
{
    for (int j = 0; j < n; j++)
    {
        std::vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(x[i][j]);
        }

        int dig = 1;
        int m = std::to_string(*std::max_element(temp.begin(), temp.end())).size();
        for (int l = 0; l < m; l++)
        {
            std::vector<std::vector<int>> digit(10);
            for (int i2 = 0; i2 < n; i2++)
            {
                digit[(temp[i2] / dig) % 10].push_back(temp[i2]);
            }
            dig *= 10;
            temp.clear();
            for (int k = 9; k >= 0; k--)
            {
                for (auto a1: digit[k])
                {
                    temp.push_back(a1);
                }
            }
        }


        for (int i = 0; i < n; i++)
        {
            x[i][j] = temp[i];
        }
    }
}


int main()
{
    int n;
    in >> n;
    std::vector<std::vector<int>> x;
    x = inFile(n);
    lsd(x, n);
    print(x, n);
    return 0;
}
