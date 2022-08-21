#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 256

int leggi_vettore(int dim_max, int v[DIM_MAX]);
void scorrimento_circolare(int dim, int v[DIM_MAX]);
void stampa_vettore(int dim, int v[DIM_MAX]);

int main()
{
    int dim;
    int v[DIM_MAX];

    dim = leggi_vettore(DIM_MAX, v);

    scorrimento_circolare(dim, v);

    stampa_vettore(dim, v);

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

void scorrimento_circolare(int dim, int v[])
{
    
    printf("Applico lo scorrimento...\n");
    int i;
    int temp = v[dim -1];

    for(i = dim - 2; i >= 0; i--)
    {
        v[i+1] = v[i];
    }

    v[0] = temp;

    return;
}

void stampa_vettore(int dim, int v[])
{
    int i;

    for(i=0; i<dim; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
    return;
}