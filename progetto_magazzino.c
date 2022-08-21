#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define DIM_MAX 256
#define MAX_ARTICOLI 100
#define DIM_MAX_STR 64

struct articolo
{
   char nome[32];
   int  q;
};

struct articolo estrai_dati(char s[DIM_MAX]);
int leggi_magazzino(int dim_max, FILE *f_magazzino, struct articolo articoli[MAX_ARTICOLI]);
void gestisci_magazzino_e_progetto(int dim_max, FILE *f_progetto, struct articolo articoli[MAX_ARTICOLI], int n_articoli);
int cerca_in_magazzino(char articolo[DIM_MAX_STR], struct articolo articoli[MAX_ARTICOLI], int n_articoli);

int main()
{ 
    struct articolo articoli[MAX_ARTICOLI];
    int n_articoli;  
    FILE *f_magazzino;
    FILE *f_progetto;
    char nome_file_magazzino[DIM_MAX_STR];
    char nome_file_progetto[DIM_MAX_STR];

    printf("nome del file magazzino: ");
    scanf("%s", nome_file_magazzino);
    
    printf("nome del file progetto: ");
    scanf("%s", nome_file_progetto);


    if((f_magazzino = fopen(nome_file_magazzino, "r")) == NULL)
    {
        printf("Errore apertura file magazzino\n");
        exit(EXIT_FAILURE);
    }

    if((f_progetto = fopen(nome_file_progetto, "r")) == NULL)
    {
        printf("Errore apertura file progetto\n");
        exit(EXIT_FAILURE);
    }

    n_articoli = leggi_magazzino(DIM_MAX, f_magazzino, articoli);

    gestisci_magazzino_e_progetto(DIM_MAX, f_progetto, articoli, n_articoli);

    fclose(f_magazzino);

    return EXIT_SUCCESS;
}

int leggi_magazzino(int dim_max, FILE *f_magazzino, struct articolo articoli[])
{
    char s[DIM_MAX];
    int i = 0;

    while(fgets(s, DIM_MAX, f_magazzino) != NULL && i < dim_max)
    {

        if(i > MAX_ARTICOLI)
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


void gestisci_magazzino_e_progetto(int dim_max, FILE *f_progetto, struct articolo articoli[], int n_articoli)
{
    struct articolo articolo_corrente;
    int i;
    char s[DIM_MAX_STR];

    while(fgets(s, dim_max, f_progetto) != NULL)
    {
        articolo_corrente = estrai_dati(s);

        if((i = cerca_in_magazzino(articolo_corrente.nome, articoli, n_articoli)) == -1)
        {
            printf("%s: %d\n", articolo_corrente.nome, articolo_corrente.q);
        }
        else
        {
            if(articolo_corrente.q > articoli[i].q)
                printf("%s: %d\n", articolo_corrente.nome, articolo_corrente.q - articoli[i].q);
        }
    }
    return;
}

int cerca_in_magazzino(char articolo[], struct articolo articoli[], int n_articoli)
{
    int i;
    for(i = 0; i < n_articoli; i++)
    {
        if(strcmp(articoli[i].nome, articolo) == 0)
        {
            return i;
        }
    }
    return -1;
}