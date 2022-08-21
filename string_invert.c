#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 64

void inverti_parole (char a[DIM_MAX]);
void swap_char(char *p_a, char *b_p);

int main()
{
    char s[DIM_MAX];

    fgets(s, DIM_MAX, stdin);


    inverti_parole(s);


    printf("%s", s);
}

void inverti_parole (char a[])
{
    int i = 0;
    int j = 0;;

    while(a[i] != '\0')
    {
        
    }

    return;
}

void swap_char(char *p_a, char *p_b)
{
    char temp;
   
    temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;

    return;
}