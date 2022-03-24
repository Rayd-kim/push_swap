#include <stdio.h>
#include <stdlib.h>

char    *check(char *str)
{
    char    *a;

    a = (char *)malloc(11);
    if (a == 0)
        return (NULL);
    for (int i = 0; i < 11; i++)
        a[i] = str[i];
    return (a);
}


int main(void)
{
    char    *a;
    char    k[11] = "0123456789";

    if ((a = check(k)) != NULL)
    {   
        free(a);
        printf("%s\n", a);
        printf("Error\n");
        return 0;
    }
    else
    {
        printf("%s\n", a);
        printf("OK\n");
    }
    return 0;
}