#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define DIM_MAX 256

struct articolo
{
   char nome[32];
   int  q;
};

void stampa_magazzino(int n_articoli, struct articolo articoli[100]);
struct articolo estrai_dati(char s[DIM_MAX]);
int leggi_magazzino(int dim_max, FILE *f_p, struct articolo articoli[100]);

int main()
{
    
    struct articolo articoli[100];
    int n_articoli;  
    FILE *f_magazzino;
    char nome_file[64];

    printf("nome del file magazzino: ");
    scanf("%s", nome_file);
    
    printf("nome del file magazzino: ");
    scanf("%s", nome_file);


    if((f_magazzino = fopen(nome_file, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    n_articoli = leggi_magazzino(DIM_MAX, f_magazzino, articoli);

    stampa_magazzino(n_articoli, articoli);

    fclose(f_magazzino);

    return EXIT_SUCCESS;
}

int leggi_magazzino(int dim_max, FILE *f_p, struct articolo articoli[])
{
    char s[DIM_MAX];
    int i = 0;

    while(fgets(s, dim_max, f_p) != NULL && i< dim_max)
    {

        if(i > 100)
        {
            printf("Superato il numero massimo di articoli\n");
        }     
        else
        {
            articoli[i] = estrai_dati(s);
            i++;
        }
    }
    return i;
}

struct articolo estrai_dati(char s[DIM_MAX])
{
    int i=0;
    int j=0;
    struct articolo a;
    char t[64];

    while(s[i] != '"')
    {
        i++;
    }

    i++;

    while(s[i] != '"')
    {
        a.nome[j] = s[i];
        i++;
        j++;
    }

    a.nome[j] = '\0';
    i++;

    while (!isdigit(s[i]))
      i++;

   j = 0;
   while (s[i] != '\0')
   {
      t[j] = s[i];
      i++;
      j++;
   }
   t[j] = '\0';

   a.q = atoi(t);
   return a;
}

void stampa_magazzino(int n_articoli, struct articolo articoli[100])
{
    int i;
    for(i = 0; i < n_articoli; i++)
    {
        printf("%s: %d\n", articoli[i].nome, articoli[i].q);
    }

    return;
}

