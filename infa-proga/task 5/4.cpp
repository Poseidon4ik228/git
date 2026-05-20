#include "stack.cpp"
#include <iostream>
#include <string>


int main()
{
    std::string a = "aeiouy";
    int n;
    std::cout << "n = "; std::cin >> n;
    stack<char>* h = nullptr;
    char x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        push(h, x);
    }
    reverse(h);


    stack<char>* vowels = nullptr;
    stack<char>* consonants = nullptr;
    while (h)
    {
        if (a.find(h->inf) != std::string::npos)
        {
            push(vowels, pop(h));
        }
        else
        {
            push(consonants, pop(h));
        }
    }
    reverse(consonants);
    while (consonants)
    {
        push(vowels, pop(consonants));
    }
    reverse(vowels);

    while(vowels)
    {
        std::cout << pop(vowels) << " ";
    }
    std::cout << "\n";
    return 0;
}
