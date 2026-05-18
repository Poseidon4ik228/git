#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>


std::ifstream in("input1.txt");
std::ofstream out("output1.txt");


struct date
{
    int dd, mm, yy;
};


struct people
{
    std::string Surname;
    std::string Post;
    date DateOfBirth;
    int Experience;
    int Salary;
};


date Str_to_Date (std::string str)
{
    date x;
    std::string temp = str.substr(0, 2);
    x.dd = std::atoi(temp.c_str());
    temp = str.substr(3, 2);
    x.mm = std::atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.yy = std::atoi(temp.c_str());
    return x;
}


std::vector<people> inFile()
{
    std::vector<people> x;
    people temp;
    std::string tmp;
    while(in >> temp.Surname >> temp.Post >> tmp >> temp.Experience >> temp.Salary)
    {
        temp.DateOfBirth = Str_to_Date(tmp);
        x.push_back(temp);
    }
    return x;
}


void print(people x)
{
    out << std::setw(25) << std::left << x.Surname;
    out << std::setw(25) << std::left << x.Post;
    if (x.DateOfBirth.dd < 10)
    {
        out << std::left << '0' << x.DateOfBirth.dd << '.';
    }
    else
    {
        out << std::left << x.DateOfBirth.dd << '.';
    }
    if (x.DateOfBirth.mm < 10)
    {
        out << '0' << x.DateOfBirth.mm << '.';
    }
    else
    {
        out << x.DateOfBirth.mm << '.';
    }
    out << std::left << std::setw(10) << x.DateOfBirth.yy;
    out << std::left << std::setw(10) << x.Experience;
    out << std::left << std::setw(10) << x.Salary << "\n";
}


bool operator > (const people& a, const people& b)
{
    if (a.Experience > b.Experience)
    {
        return true;
    }
    return false;
}


void bucket_sort (std::vector<people>& a)
{
    int max = a[0].Experience, min = a[0].Experience;
    for (auto& x: a)
    {
        max = std::max(max, x.Experience);
        min = std::min(min, x.Experience);
    }
    int k = (max - min) / 6;
    std::vector<std::vector<people>> bucket(k + 1);
    for (auto& x: a)
    {
        int l = (x.Experience - min) * (k + 1) / (max - min + 1);
        bucket[l].push_back(x);
    }

    for (auto& x: bucket)
    {
        for (int i = 1; i < x.size(); i++)
        {
            people key = x[i];
            int j = i - 1;
            while (j >= 0 && x[j] > key)
            {
                x[j + 1] = x[j];
                j--;
            }
            x[j + 1] = key;
        }
    }

    a.clear();
    for (auto& x: bucket)
    {
        for (auto& y: x)
        {
            a.push_back(y);
        }
    }
}


int main()
{
    std::vector<people> x;
    x = inFile();
    bucket_sort(x);
    for (int i = 0; i < x.size(); i++)
    {
        print(x[i]);
    }
    return 0;
}
