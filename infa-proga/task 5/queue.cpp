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
