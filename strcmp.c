#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 64
int strcompare (char a[DIM_MAX], char b[DIM_MAX]);
int max(int a, int b);

int main()
{
    int result;
    char s[DIM_MAX];
    char t[DIM_MAX];

    printf("prima stringa: ");
    fgets(t, DIM_MAX, stdin);

    printf("seconda stringa: ");
    fgets(s, DIM_MAX, stdin);

    result = strcompare(t,s);

    printf("strcompare ha restituito %d\n", result);
}

int strcompare (char a[], char b[])
{
    int max_len;
    int i = 0;

    max_len = max(strlen(a), strlen(b));

    printf("max = %d\n", max_len);

    for(i = 0; i < max_len - 1; i++)
    {
        printf("s[%d] = %c\n", i, a[i]);
        printf("t[%d] = %c\n", i, b[i]);
        if(a[i] != b[i])
        {
            printf("i = %d\n", i);
            if( (a[i] - 'a') > (b[i]- 'a') )
                return 1;
            else
                return -1;
        }
    }

    return 0;
}

int max(int a, int b)
{
    if(a >= b)
        return a;
    
    return b;
}