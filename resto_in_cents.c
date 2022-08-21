#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 20

int leggi_vettore(int dim_max, int v[DIM_MAX]);
int resto_in_monete (int resto, int dim, int valori[], int numero_monete[]);
void stampa_vettore(int dim, int v[DIM_MAX]);
void inizializza_vettore(int dim, int v[DIM_MAX]);

int main()
{
    int dim, resto;
    int valori[DIM_MAX];
    int numero_monete[DIM_MAX];

    dim = leggi_vettore(DIM_MAX, valori);

    printf("inserisci il valore totale del resto: ");
    scanf("%d", &resto);

    inizializza_vettore(dim, numero_monete);

    resto_in_monete(resto, dim, valori, numero_monete );

    stampa_vettore(dim, numero_monete);

    return EXIT_SUCCESS;
}

int leggi_vettore(int dim_max, int v[])
{
    int i;
    int dim;
    printf("Inserisci il numero di valori da scrivere nel vettore: ");
    scanf("%d", &dim);
    
    while (dim > DIM_MAX)
    {
            printf("Numero troppo elevato: reinseriscilo:");
            scanf("%d", &dim);
    }

    for(i = 0; i < dim; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    return dim;      
}

int resto_in_monete(int resto, int dim, int valori[], int numero_monete[])
{
    printf("calcolo il resto...\n");
    int i = 1;

    while(resto != 0)
    {
        if(resto < valori[dim - i])
        {
            i++;
        }
        else
        {
            resto = resto- valori[dim-i];
            numero_monete[dim-i]++;
        }

    }

    return i;
}

void inizializza_vettore(int dim, int v[])
{
    int i;
    for(i=0; i < dim; i++)
    {
        v[i] = 0;
    }

    return;
}

void stampa_vettore(int dim, int v[])
{
    int i;

    for(i=0; i < dim; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
    return;
}