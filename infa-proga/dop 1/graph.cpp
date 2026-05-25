#include <iostream>
#include <vector>
#include <sstream>
#include <string>


// ===========================Queue============================
struct queue
{
    int inf;
    queue* next;
};


void push(queue*& h, queue*& t, int x)
{
    queue* r = new queue;
    r->inf = x;
    r->next = nullptr;

    if (!h && !t)
    {
        h = t = r;
    }

    else
    {
        t->next = r;
        t = r;
    }
}


int pop(queue*& h, queue*& t)
{
    queue* r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
    {
        t = nullptr;
    }
    delete r;
    return i;
}


int max(queue*& h)
{
    int m = h->inf;
    queue* res = h->next;
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
//=============================================================


//======================================Stack==================
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
//=============================================================


//==================================BFS========================
void BFS(const std::vector<std::vector<int>>& Gr, int n, int x)
{
    queue* pos_h = nullptr;
    queue* pos_t = nullptr;
    std::vector<int> A(n, 0);
    for (int step = 0; step < n + 1; step++)
    {
        if (step != 0)
        {
            x = step - 1;
        }
        if (A[x] == 0)
        {
            A[x] = 1;
            push(pos_h, pos_t, x);
            std::cout << x << " ";
            while (pos_h)
            {
                x = pop(pos_h, pos_t);
                for (int i = 0; i < Gr[x].size(); i++)
                {
                    if (A[Gr[x][i]] == 0)
                    {
                        int y = Gr[x][i];
                        A[y] = 1;
                        push(pos_h, pos_t, y);
                        std::cout << y << " ";
                    }
                }
            }
        }
    }
    std::cout << "\n";
}
//========================================================


//=================================DFS=======================
void DFS(const std::vector<std::vector<int>>& Gr, int n, int x)
{
    stack<int>* pos = nullptr;
    std::vector<int> A (n, 0);
    for (int step = 0; step < n + 1; step++)
    {
        if (step != 0)
        {
            x = step - 1;
        }
        if (A[x] == 0)
        {
            A[x] = 1;
            push(pos, x);
            std::cout << x << " ";
            int y;
            while (pos)
            {
                bool fl = false;
                x = pos->inf;
                for (int i = 0; i < Gr[x].size(); i++)
                {
                    if (A[Gr[x][i]] == 0)
                    {
                        y = Gr[x][i];
                        fl = true;
                        break;
                    }
                }
                if (fl == true)
                {
                    A[y] = 1;
                    push(pos, y);
                    std::cout << y << " ";
                }
                else
                {
                    pop(pos);
                }
            }
        }
    }
    std::cout << "\n";
}


int main()
{
    int n, x;
    std::cout << "n = "; std::cin >> n;
    std::cout << "graph:" << "\n"; std::cin.ignore();
    std::vector<std::vector<int>> Gr(n);
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::string temp;
        while (ss >> temp)
        {
            Gr[i].push_back(std::stoi(temp));
        }
    }
    std::cout << "x = "; std::cin >> x;
    std::cout << "\n";

    BFS(Gr, n, x);
    DFS(Gr, n, x);
    return 0;
}
