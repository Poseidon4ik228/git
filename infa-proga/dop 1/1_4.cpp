#include <iostream>
#include <string>
#include <sstream>


template <typename T>
struct stack
{
    T inf;
    stack<T>* next;
};


template <typename T>
void push(stack<T>*& h, T x)
{
    stack<T>* r = new stack<T>;
    r->inf = x;
    r->next = h;
    h = r;
}


template <typename T>
T pop(stack<T>*& h)
{
    stack<T>* r = h;
    T i = h->inf;
    h = h->next;
    delete r;
    return i;
}


template <typename T>
void reverse(stack<T>*& h)
{
    stack<T>* h1 = nullptr;
    while (h)
    {
        push(h1, pop(h));
    }
    h = h1;
}


template <typename T>
T max(stack<T>* h)
{
    T m = h->inf;
    stack<T>* res = h->next;
    while(res)
    {
        if (m <= res->inf)
        {
            m = res->inf;
        }
        res = res->next;
    }
    return m;
}


template <typename T>
T min(stack<T>* h)
{
    T m = h->inf;
    stack<T>* res = h->next;
    while(res)
    {
        if (m >= res->inf)
        {
            m = res->inf;
        }
        res = res->next;
    }
    return m;
}


template <typename T>
void insert(stack<T>*& h, T x, int index)
{
    int i = 0;
    stack<T>* h1 = nullptr;
    while (h)
    {
        if (i == index)
        {
            push(h1, x);
        }
        push(h1, pop(h));
        i++;
    }
    reverse(h1);
    h = h1;
}



int main()
{
    std::string s;
    std::cout << "str: "; std::getline(std::cin, s);
    stack<int>* v = nullptr;
    std::stringstream ss(s);
    std::string temp;

    while (ss >> temp)
    {
        if (temp == "+")
        {
            int a = pop(v);
            int b = pop(v);
            push(v, a + b);
        }
        else if (temp == "-")
        {
            int a = pop(v);
            int b = pop(v);
            push(v, b - a);
        }
        else if (temp == "*")
        {
            int a = pop(v);
            int b = pop(v);
            push(v, a * b);
        }
        else if (temp == "/")
        {
            int a = pop(v);
            int b = pop(v);
            push(v, b / a);
        }
        else
        {
            push(v, std::stoi(temp));
        }
    }
    std::cout << v->inf << std::endl;
}
