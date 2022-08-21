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

int leggi_regali(int max_regali, FILE *f_regali, struct regalo regali[MAX_REGALI]);
double calcola_carta(int n_regali, struct regalo regali[MAX_REGALI]);
double superficie(double x, double y, double z);

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

int leggi_regali(int max_regali, FILE *f_regali, struct regalo regali[])
{
    char decorazione[DIM_MAX_STR];
    int i = 0;

    while(fscanf(f_regali, "%s %lf %lf %lf %s", regali[i].nome, &regali[i].x, &regali[i].y, &regali[i].z, decorazione) != EOF && i < max_regali)
    {
        if(strcmp(decorazione, "grezza") == 0)
            regali[i].decorato = 0;

        if(strcmp(decorazione, "decorata") == 0)
            regali[i].decorato = 1;

        i++;
    }

    return i;
}

double calcola_carta(int n_regali, struct regalo regali[])
{
    double s = 0;
    double carta = 0;
    double carta_regalo_corrente = 0;

    int i;
    for(i = 0; i < n_regali; i++)
    {
        if(regali[i].decorato == 0)
        {
            s = superficie(regali[i].x, regali[i].y, regali[i].z);
            carta_regalo_corrente = s + (s * (double) 15/100) ;
            carta = carta + carta_regalo_corrente;
        }
    }
    return carta / (double) 10000;
}

double superficie(double x, double y, double z)
{
    double sup;

    sup = (double) 2 * (  (x*y) + (x*z) + (y*z)   );

    return sup;
}