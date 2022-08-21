#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 64

void strcatenate (char t[DIM_MAX], char s[DIM_MAX]);


int main()
{
    char s[DIM_MAX];
    char t[DIM_MAX];
    printf("prima stringa: ");
    fgets(t, DIM_MAX, stdin);

    printf("seconda stringa: ");
    fgets(s ,DIM_MAX, stdin);

    strcatenate(t,s);  
}

void strcatenate (char t[DIM_MAX], char s[DIM_MAX])
{
    int i = 0;
    int j = 0;

    while(t[i] != '\0')
        i++;

    i--;
    while ((t[i] = s[j]) != '\0')
    {
        i++;
        j++;
    }

    puts(t);
    return;
 
}