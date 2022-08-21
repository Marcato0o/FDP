#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define DIM_MAX 256
#define MAX_REGALI 100
#define DIM_MAX_STR 64


struct regalo
{
   char nome[32];
   double x;
   double y;
   double z;
   int decorato;
};

int main()
{ 
    struct regalo regali[MAX_REGALI];
    int n_regali;

    FILE *f_regali;
    char nome_file_regali[DIM_MAX_STR];

    double carta;

    printf("nome del file dei regali: ");
    scanf("%s", nome_file_regali);

    if((f_regali = fopen(nome_file_regali, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    n_regali = leggi_regali(MAX_REGALI, f_regali, regali);

    carta = calcola_carta(n_regali, regali);

    printf("servono %lf metri quadrati di carta da regalo\n",carta); 

    fclose(f_regali);

    return EXIT_SUCCESS;
}