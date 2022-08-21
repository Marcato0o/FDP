#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 100
#define VAL_MIN 0
#define VAL_MAX 20

int leggi_vettore(int v[DIM_MAX], int dim);
int conta_occorrenze(int dim, int v[DIM_MAX], int occorrenze[DIM_MAX]);
void isto_vert(int dim, int v[DIM_MAX], int dim_occorrenze, int occorrenze[DIM_MAX]);
int max_in_vettore(int dim, int v[  DIM_MAX]);
void inizializza_vettore(int dim, int v[]);

int main()
{
    int n, dim_occorrenze;
    int v[DIM_MAX];
    int occorrenze[DIM_MAX];


    n = leggi_vettore(v, DIM_MAX);
    inizializza_vettore(100, occorrenze);
    
    dim_occorrenze = conta_occorrenze(n,v, occorrenze);
    printf("dim_occ = %d\n", dim_occorrenze);

    isto_vert(n, v, dim_occorrenze, occorrenze);

    return EXIT_SUCCESS;
}

int leggi_vettore(int v[], int dim)
{
   int n, i, j=1;

   scanf("%d", &n);

   printf("inserisci il numero di valori da scrivere nel vettore: v[0] =");
   while(j < n)
   {
      printf(" v[%d] =", j);
      j++;
   }

   i=0;
   while(i < n && i < DIM_MAX)
   {
      scanf("%d", &v[i]);
      if(v[i] >= VAL_MIN && v[i] <= VAL_MAX)
      {
         i++;
      }
      else
      {
         printf("è stato scartato il valore non valido %d \n ", v[i]);
      }
   }
   return i;
}

int conta_occorrenze(int dim, int v[], int occorrenze[])
{
    int i;
    int j=0; 

    for(i = 0; i < dim; i++)
    {
        j = v[i];

        occorrenze[j]++;
    }

    return (max_in_vettore(dim, v) + 1);
}


void isto_vert(int dim, int v[], int dim_occorrenze, int occorrenze[])
{
    int max_occorrenze, i,j,k;

    max_occorrenze = max_in_vettore(dim_occorrenze, occorrenze);

    for(i = 0; i < (max_occorrenze); i++)
    {
        for(j = 0; j < dim_occorrenze; j++)
        {
            if(max_occorrenze - i <= occorrenze[j])
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

    for(k = 0; k < dim_occorrenze; k++)
    {
        printf("%2d ", k);
    }
    printf("\n");

    return;
}

int max_in_vettore(int dim, int v[])
{
    int i,max;

    max = v[0]; 

    for(i = 1; i < dim; i++)
    {
        if (v[i] > max)
            max = v[i];
    }

    return max;
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