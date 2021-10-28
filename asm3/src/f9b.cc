unsigned long g2(unsigned long *l1, unsigned long l2)
{
    unsigned long l3 = l2 << 4;
    l3 = *((char *)l1 + l3);
    l3 -= *(l1 + l2);
    return l3;
}