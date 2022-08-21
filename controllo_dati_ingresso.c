#include "stdio.h"
#include "stdlib.h"

int leggi_num_con_controllo(int max, int min);

int main()
{
    int min,max;
    int somma = 0;  
    double media = 0;
    int num;
    int i=0;

    scanf("%d-%d", &min, &max);
    while((num = leggi_num_con_controllo(max, min)) != 1)
    {
        somma = somma + num;
        i++;
    }
    media = (double)somma / (double) i;
    printf("%lf", media);
}

int leggi_num_con_controllo(int max, int min)
{
    int num;
    scanf("%d",&num);

    if((num < min || num > max )&& num != 1)
    {
        printf("Ripeti inserimento\n");
    }
    return num;
}


