#include <iostream>


struct list
{
    int inf;
    list* prev;
    list* next;
};


void push(list*& h, list*& t, int x)
{
    list* p = new list;
    p->inf = x;
    p->next = nullptr;
    if (!h && !t)
    {
        p->prev = nullptr;
        h = p;
    }
    else
    {
        p->prev = t;
        t->next = p;
    }
    t = p;
}


void print(list*& h, list*& t)
{
    list* p = h;
    while (p)
    {
        std::cout << p->inf << " ";
        p = p->next;
    }
    std::cout << "\n";
}


list* find(list*& h, list*& t, int x)
{
    list* p = h;
    while (p)
    {
        if (p->inf == x)
        {
            break;
        }
        p = p->next;
    }
    return p;
}


void insert_after(list*& h, list*& t, list* r, int x)
{
    list* p = new list;
    p->inf = x;
    if (t == r)
    {
        t->next = p;
        p->next = nullptr;
        p->prev = t;
        t = p;
    }
    else
    {
        r->next->prev = p;
        p->next = r->next;
        r->next = p;
        p->prev = r;
    }
}


void del_node(list*& h, list*& t, list* r)
{
    if (r == h && r == t)
    {
        h = nullptr;
        t = nullptr;
    }
    else if (r == h)
    {
        h = h->next;
        h->prev = nullptr;
    }
    else if (r == t)
    {
        t = t->prev;
        t->next = nullptr;
    }
    else
    {
        r->prev->next = r->next;
        r->next->prev = r->prev;
    }
    delete r;
}


void del_list(list*& h, list*& t)
{
    while(h)
    {
        list* p = h;
        h = h->next;
        delete p;
    }
    t = nullptr;
}


void reverse(list*& h, list*& t) {
    list* current = h;
    while (current) {
        list* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    list* temp_ptr = h;
    h = t;
    t = temp_ptr;
}


int sum(list*& h, list*& t)
{
    int s = 0;
    list* temp = h;
    while (temp)
    {
        s += temp->inf;
        temp = temp->next;
    }
    return s;
}
