struct ll
{
    ll *next;
};

int g3(ll *head)
{
    int length = 0;
    if (head == nullptr)
    {
        return length;
    }
    while (head != nullptr)
    {
        head = head->next;
        length += 1;
    }
    return length;
}