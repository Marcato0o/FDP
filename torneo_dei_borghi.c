#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX_BORGHI 15
#define N_MAX_PARTECIPANTI 20

struct borgo
{
    char nome[32];
    int numero_partecipanti;
    char partecipanti[20][32];
    int punteggio;
};

int leggi_borghi(int n_max_borghi, FILE *f_borghi, struct borgo borghi[N_MAX_BORGHI]);
void calcola_punteggi(int n_borghi, struct borgo borghi[N_MAX_BORGHI], FILE *f_partecipanti);
int cerca_partecipante(int n_borghi, struct borgo borghi[N_MAX_BORGHI], char partecipante[32]);
void stampa_punteggi(int n_borghi, struct borgo borghi[]);

int main(int argc, char *argv[])
{
    struct borgo borghi[N_MAX_BORGHI];
    char nome_file_borghi[32], nome_file_partecipanti[32];
    FILE *f_borghi, *f_partecipanti;

    
    int n_borghi;

    strcpy(nome_file_borghi, argv[1]);
    strcpy(nome_file_partecipanti, argv[2]);

    printf("%s %s\n", nome_file_borghi, nome_file_partecipanti);

    if((f_borghi = fopen(nome_file_borghi, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    if((f_partecipanti = fopen(nome_file_partecipanti, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    n_borghi = leggi_borghi(N_MAX_BORGHI, f_borghi, borghi);

    calcola_punteggi(n_borghi, borghi, f_partecipanti);
    stampa_punteggi(n_borghi, borghi);
    fclose(f_partecipanti);
    fclose(f_borghi);

    return EXIT_SUCCESS;

}

int leggi_borghi(int n_max_borghi, FILE *f_borghi, struct borgo borghi[])
{
    int n_borghi;
    int i,j,k;
    int n_partecipanti;

    fscanf(f_borghi, "%d", &n_borghi);

    for(i = 0; i < n_borghi; i++)
    {
        fscanf(f_borghi,"%s", borghi[i].nome);
    }
    for(j = 0; j < n_borghi; j++)
    {
        fscanf(f_borghi, "%*s %d", &n_partecipanti);
        borghi[j].numero_partecipanti = n_partecipanti;

        for(k = 0; k < n_partecipanti; k++)
        {
            fscanf(f_borghi,"%s", borghi[j].partecipanti[k]);
        }
    }

    return n_borghi;
}

void calcola_punteggi(int n_borghi, struct borgo borghi[], FILE *f_partecipanti)
{
    char partecipante_corrente[32];
    int punteggio_partecipante;
    int indice;

    while(fscanf(f_partecipanti,"%s %d", partecipante_corrente, &punteggio_partecipante) != EOF)
    {
        indice = cerca_partecipante(n_borghi, borghi, partecipante_corrente);

        if(indice != -1)
        {
            borghi[indice].punteggio = borghi[indice].punteggio + punteggio_partecipante;
        }
    }
}

int cerca_partecipante(int n_borghi, struct borgo borghi[], char partecipante[])
{
    int i,j;
    for(i = 0; i < n_borghi; i++)
    {
        for(j = 0; j < borghi[i].numero_partecipanti; j++)
        {
            if(strcmp(borghi[i].partecipanti[j], partecipante) == 0)
                return i;
        }
        
    }
    return -1;
}

void stampa_punteggi(int n_borghi, struct borgo borghi[])
{
    int i;
    for(i=0; i<n_borghi; i++)
    {
        printf("%s  %d\n", borghi[i].nome, borghi[i].punteggio);
    }
}




