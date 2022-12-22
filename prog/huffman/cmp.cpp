#include "cmp.hpp"

int comp(const alphabetic* v1, const alphabetic* v2)
{
    long long a = v1->amount, b = v2->amount;
    if (a < b)
        return 1;
    return -1;
}


char* create_compressed_name(char* original_name)
{
    char* res = new char[strlen(original_name) + 25];
    char* res_copy = res;
    char added[17] = "_compressed.comp";
    
    while (*original_name != '.')
    {
        *res = *original_name;
        ++res;
        ++original_name;
    }

    for (int i = 0; i < 17; i++)
    {
        *res = added[i];
        ++res;
    }

    return res_copy;
}

void compress()
{
    return;
}

void decompress()
{
    return;
}