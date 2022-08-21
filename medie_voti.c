#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX_VERIFICHE 100
#define N_MAX_STUDENTI 50

struct studente
{
    char nome[64];
    char cognome[64];
};

struct data
{
    int giorno;
    int mese;
    int anno;
};
struct verifica
{
    struct studente studente;
    struct data data;
    double voto;
    int flag;
};

int leggi_verifiche(int n_max_verifiche, FILE *f_verifiche, struct verifica verifiche[N_MAX_VERIFICHE]);
struct verifica estrai_dati(char s[500]);
void stampa_verifiche(int n_verifiche, struct verifica verifiche[N_MAX_VERIFICHE]);
void stampa_studenti(int n_studenti, struct studente studenti[N_MAX_STUDENTI]);
int carica_studente(int n_verifiche, struct verifica verifiche[N_MAX_VERIFICHE], struct studente studenti[N_MAX_STUDENTI]);



int main(int argc, char *argv[])
{
    struct verifica verifiche[N_MAX_VERIFICHE];
    char nome_file_verifiche[32], nome_file_medie[32];
    FILE *f_verifiche, *f_medie;
    struct studente studenti[N_MAX_STUDENTI];
    
    int n_verifiche;
    int n_studenti;

    strcpy(nome_file_verifiche, argv[1]);
    strcpy(nome_file_medie, argv[2]);

    printf("%s %s\n", nome_file_verifiche, nome_file_medie);

    if((f_verifiche = fopen(nome_file_verifiche, "r")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    if((f_medie = fopen(nome_file_medie, "w")) == NULL)
    {
        printf("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    n_verifiche = leggi_verifiche(N_MAX_VERIFICHE, f_verifiche, verifiche);
    n_studenti = carica_studente(studenti, verifiche);

    stampa_verifiche(n_verifiche, verifiche);
    printf("\n");
    stampa_studenti(n_verifiche, verifiche, studenti);
    return EXIT_SUCCESS;   
}

int leggi_verifiche(int n_max_verifiche, FILE *f_verifiche, struct verifica verifiche[])
{
    char s[256];
    int i = 0;

    while(fgets(s, 5000, f_verifiche) != NULL)
    {
        if(i > n_max_verifiche)
        {
            printf("numero di verifiche superato\n");
        }
        else
        {
            verifiche[i] = estrai_dati(s);
            i++;
        }
    }
    return i;
}

struct verifica estrai_dati(char s[])
{
    int i = 0; 
    int j = 0;
    struct verifica verifica;

    char a[32], m[32], g[32], voto[32];

    while(s[i] != ',')
    {
        verifica.studente.cognome[j] = s[i]; 
        i++;
        j++;
    }
    verifica.studente.cognome[j] = '\0';

    j = 0;
    i++;
    i++;

    while(s[i] != ',')
    {
        verifica.studente.nome[j] = s[i]; 
        i++;
        j++;
    }
    verifica.studente.nome[j] = '\0';

    j = 0;
    i++;
    i++;
    while(s[i] != '/')
    {
        g[j] = s[i];
        i++;
        j++; 
    }
    g[j] = '\0';
    i++;
    j = 0;

    while(s[i] != '/')
    {
        m[j] = s[i];
        i++;
        j++; 
    }
    m[j] = '\0';
    i++;
    j = 0;

    while(s[i] != ',')
    {
        a[j] = s[i];
        i++;
        j++; 
    }
    a[j] = '\0';
    i++;
    i++;
    j = 0;

    while(s[i] != '.')
    {
        voto[j] = s[i];
        i++;
        j++;
    }

    verifica.data.giorno = atoi(g);
    verifica.data.mese = atoi(m); 
    verifica.data.anno = atoi(a);
    verifica.voto = atoi(voto);
    verifica.flag = 0;

    return verifica;
}

void stampa_verifiche(int n_verifiche, struct verifica verifiche[])
{
    int i;
    for(i = 0; i<n_verifiche; i++)
    {
        printf("%s %s: %d %d %d - %.0lf\n", verifiche[i].studente.nome, verifiche[i].studente.cognome, verifiche[i].data.giorno,verifiche[i].data.mese, verifiche[i].data.anno, verifiche[i].voto);
    }
    return;
}

int carica_studente(int n_verifiche, struct verifica verifiche[], struct studente studenti[])
{
    int i = 0;
    int n_studenti;
    for(i = 0; i < n_studenti; i++)
    {
        if(cerca_studente(n_studenti, verifiche[i].studente, studenti) == -1)
        {   
            studenti[n_studenti].nome = verifiche[i].studente.nome;
            studenti[n_studenti].cognome = verifiche[i].studente.cognome;
            n_studenti++;
        }
    }
    return n_studenti;
}

void stampa_studenti(int n_studenti, struct studente studenti[])
{
    int i;
    for(i=0; i<n_studenti; i++)
    {
        printf("%s %s\n", studenti[i].nome, studenti[i].cognome);
    }
    return i;
}

int cerca_studente()



