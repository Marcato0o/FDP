#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

void inizializza_vettore(int dim, int v[N_MAX]);
int riempi_vettore(int dim_max, int v[N_MAX]);
int conta_occorrenze(int n_valori, int v[N_MAX], int occorrenze[100]);
void stampa_isto_vert(int n_occorrenze, int occorrenze[100]);
int max(int dim_max, int v[N_MAX]);

int main()
{
    int v[N_MAX];
    int n_valori, n_occorrenze;
    int occorrenze[200];

    n_valori = riempi_vettore(N_MAX, v);

    inizializza_vettore(N_MAX, occorrenze);

    n_occorrenze = conta_occorrenze(n_valori, v, occorrenze);

    stampa_isto_vert(n_occorrenze, occorrenze);
}

int riempi_vettore(int dim_max, int v[])
{
    int i=0;
    int j=0;
    int k = 0; 
    int n;
    int n_valori;
    int val_corr;
    int scartati[100];

    printf("inserisci il numero di valori da scrivere nel vettore: ");

    scanf("%d", &n_valori);

    while(n_valori > dim_max)
        scanf("%d", &n_valori);

    while (i < n_valori)
    {
        printf("v[%d] = ", i);
        scanf("%d", &val_corr);

        if(val_corr > 20 || val_corr < 0)
        {
            scartati[k] = val_corr;
            k++;
        }
        else
        {
            v[j] = val_corr;
            j++;
        }
        i++;
    }

    for(n = 0; n < k; n++)
    {
        printf("e` stato scartato il voto non valido %d\n", scartati[n]);
    }

    printf("\n");

    return j;
}

int conta_occorrenze(int n_valori, int v[], int occorrenze[])
{
    int i;
    for(i = 0; i < n_valori; i++)
    {
        occorrenze[v[i]]++;
    }
    return max(n_valori, v);
}

void stampa_isto_vert(int n_occorrenze, int occorrenze[])
{
    int i,j,k;
    int n_righe = max(n_occorrenze,occorrenze);

    for(i = 0; i < n_righe; i++)
    {
        for(j = 0; j < n_occorrenze+1; j++)
        {
            if(n_righe-i <= occorrenze[j])
                printf("  *");
            else
                printf("   ");
        }

        printf("\n");
    }

    for(k = 0; k < 21; k++)
    {
        printf(" %2d", k);
    }

    printf("\n");
}

int max(int dim_max, int v[])
{
    int max_corrente = v[0];
    int i;

    for(i = 0; i < dim_max; i++)
    {
        if(v[i] > max_corrente)
            max_corrente = v[i];
    }

    return max_corrente;
}

void inizializza_vettore(int dim, int v[])
{
    int i;
    for(i = 0; i < dim; i++)
    {
        v[i] = 0;
    }
}

