#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 256

int leggi_vettore(int dim_max, int v[DIM_MAX]);
int ricerca_lineare(int dim, int v[DIM_MAX], int indice_cercato);

int main()
{
    int v[DIM_MAX];
    int dim, valore_cercato, indice_cercato;
    int from, to;

    dim = leggi_vettore(DIM_MAX, v);

    printf("Inserisci l'elemento da cercare: ");
    scanf("%d", &valore_cercato);

    printf("inserisci l'indice del primo elemento del sottovettore in cui cercare:");
    scanf("%d", &from);

    while(from < 0)
    {
        printf("Errore, reinserisci:");
        scanf("%d", &from);
    }

    printf("inserisci l'indice dell'ultimo elemento del sottovettore in cui cercare:");
    scanf("%d", &to);

    while(to > dim)
    {
        printf("Errore, reinserisci:");
        scanf("%d", &to);
    }

    indice_cercato = ricerca_lineare(dim, v, valore_cercato);

    if(indice_cercato != -1)
        printf("v[%d] = %d \n", indice_cercato, valore_cercato);
    else
        printf("Non trovato");

    
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


int ricerca_lineare(int dim, int v[], int valore_cercato)
{
    printf("ricerca lineare...\n");
    int i = 0; 

    while (i < dim)
    {
        if (valore_cercato == v[i])
            return i;

        i++;
    }

return -1;

}
