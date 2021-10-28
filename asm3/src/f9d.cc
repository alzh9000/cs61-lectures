struct stat
{
    unsigned long l1;
    unsigned long l2;
    unsigned long l3;
};

unsigned g4(stat *stats, unsigned u1)
{
    unsigned res = u1;
    u1 *= u1;
    stats->l1 += 1;
    stats->l2 += res;
    stats->l3 += u1;
    return res;
}