#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define DIM_MAX 256
#define MAX_PRODOTTI 1000
#define DIM_MAX_STR 64
#define LUNGHEZZA_CARRELLO 1.5

struct prodotto
{
   char nome[32];
   double lunghezza;
   int flag;
};

int leggi_prodotti(int max_prodotti, FILE *f_prodotti, struct prodotto prodotti[MAX_PRODOTTI]);
void stampa_ordine(int n_prodotti, struct prodotto prodotti[MAX_PRODOTTI]);
int max_fra_intervalli(int n, struct prodotto articoli[MAX_PRODOTTI], double min, double max);

int main()
{ 
    struct prodotto prodotti[MAX_PRODOTTI];
    int n_prodotti;

    FILE *f_prodotti;
    char nome_file_prodotti[DIM_MAX_STR];

    printf("nome del file dei prodotti: ");
    scanf("%s", nome_file_prodotti);

    if((f_prodotti = fopen(nome_file_prodotti, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    n_prodotti = leggi_prodotti(MAX_PRODOTTI, f_prodotti, prodotti);

    stampa_ordine(n_prodotti, prodotti);

    fclose(f_prodotti);

    return EXIT_SUCCESS;
}

int leggi_prodotti(int max_prodotti, FILE *f_prodotti, struct prodotto prodotti[])
{
    int i = 0;
    while(fscanf(f_prodotti, "%s %lf", prodotti[i].nome, &prodotti[i].lunghezza) != EOF && i < max_prodotti)
    {
        prodotti[i].flag = 0; 
        i++;
    }

    return i;
}

void stampa_ordine(int n_prodotti, struct prodotto prodotti[])
{
    int i = 0;;
    double spazio_residuo = 1.5;
    int indice;

    while(i < n_prodotti)
    {
        indice = max_fra_intervalli(n_prodotti, prodotti, 0, spazio_residuo);
        
        if(indice == -1)
        {
            spazio_residuo = LUNGHEZZA_CARRELLO;
            printf("\n");
        }
        else
        {
            spazio_residuo = spazio_residuo - prodotti[indice].lunghezza;
            prodotti[indice].flag = 1;
            printf("/%s",prodotti[indice].nome);
            i++;
        }
    }

    printf("\n");
    return;
}

int max_fra_intervalli(int n, struct prodotto prodotti[], double min, double max)
{
    int i = 0; 
    double max_corrente = 0;
    int indice_max = -1;
    for(i = 0; i < n; i++)
    {
        if((prodotti[i].lunghezza > max_corrente) && (prodotti[i].lunghezza >= min) && (prodotti[i].lunghezza <= max) && (prodotti[i].flag == 0))
        {
            max_corrente = prodotti[i].lunghezza;
            indice_max = i;
        }
             
    }
    return indice_max;
}  