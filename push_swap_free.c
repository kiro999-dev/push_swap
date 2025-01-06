#include "push_swap.h"

void ft_free(char **ptr)
{
    int i = 0;
    if(ptr == NULL)
        return;
    while (ptr[i])
    {
        free(ptr[i]);
        ptr[i] = NULL;
        i++;
    }
    ptr = NULL;
}