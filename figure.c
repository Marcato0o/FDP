#include <stdio.h>
#include <stdlib.h>

void stampa_quadrato(int lato);
void stampa_triangolo(int lato);
void stampa_linea(int lunghezza);

int main()
{
    int num;
    char lettera;

    while((lettera = getchar()) != '\n')
    {
        if(lettera == 'L')
        {
            num = getchar() - '0'; 
            stampa_linea(num);

        }

        if(lettera == 'T')
        {
            num = getchar() - '0'; 
            stampa_triangolo(num);

        }

        if(lettera == 'Q')
        {
            num = getchar() - '0'; 
            stampa_quadrato(num);

        }
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}

void stampa_quadrato(int lato)
{
    int i,j;
    for(i = 0; i < lato; i++)
    {
        for(j = 0; j < lato; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return;
}

void stampa_triangolo(int lato)
{
    int i,j;

    for(i = 0; i < lato; i++)
    {
        for(j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return;
}
void stampa_linea(int lunghezza)
{
    int i;

    for(i = 0; i < lunghezza; i++)
    {
        printf("*");
    }
    printf("\n");
    return;
}