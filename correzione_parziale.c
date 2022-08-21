#include "dijkstra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_STAZIONI 100


struct linea
{
    int n_stazioni;
    char stazioni[MAX_STAZIONI][32];
};
struct pacco
{
    char nome[32];
    char start[32];
    char dest[32];
};


/* Funzioni da definire per la prima parte */
int carica_stazioni(char nome_file[64], char stazioni[][32]);
grafo carica_rete(char nome_file[64], char stazioni[][32], int n);
void stampa_percorso(grafo g, char stazioni[][32], int n, char s[32], char d[32]);

/* Eventuali altre funzioni possono essere aggiunte di seguito */
int cerca_stazioni(int n_stazioni, char stazione[32], char stazioni[][32]);
struct linea estrai_dati(char s[2000]);
void stampa_pacchi(char nome_file_pacchi[32], char stazioni[][32], grafo g, int n_stazioni);
struct pacco estrai_dati_pacchi(char s[2000]);
void stampa_stazioni(int n_stazioni, char stazioni[][32]);

int main(int argc, char* argv[]) 
{
    char stazioni[MAX_STAZIONI][32];
    int n_stazioni;
    grafo g;
    
    n_stazioni = carica_stazioni(argv[2], stazioni);
    stampa_stazioni(n_stazioni, stazioni);
    printf("n_stazioni = %d\n", n_stazioni);

    g = carica_rete(argv[2], stazioni, n_stazioni);

    printf("sono qui\n");

    stampa_pacchi(argv[1], stazioni, g, n_stazioni);

    return EXIT_SUCCESS;    
}

int carica_stazioni(char nome_file[], char stazioni[][32])
{
    FILE *fp;
    int i = 0; 
    int j, indice;
    int n_stazioni = 0;
    char s[2000];

    struct linea linee[100];

    if((fp = fopen(nome_file, "r")) == NULL)
    {
        printf("Errore di apertura file\n");
        exit(EXIT_SUCCESS);
    }

    while(fgets(s, 2000, fp) != NULL)
    {
        linee[i] = estrai_dati(s);

        for(j = 0; j < linee[i].n_stazioni; j++)
        {
            indice = cerca_stazioni(n_stazioni, linee[i].stazioni[j], stazioni);

            if(indice == -1)
            {
                strcpy(stazioni[n_stazioni], linee[i].stazioni[j]);
                n_stazioni++;
            }
        }
        i++;
    }
    return n_stazioni; 
}

grafo carica_rete(char nome_file[], char stazioni[][32], int n) 
{
    grafo g;
    g = crea_grafo(n, 0);

    FILE *fp; 
    int j;
    int u,v;

    struct linea linea;

    char s[2000];


    if((fp = fopen(nome_file, "r")) == NULL)
    {
        printf("Errore di apertura file\n");
        exit(EXIT_SUCCESS);
    }

    while(fgets(s, 2000, fp) != NULL)
    {
        linea = estrai_dati(s);

        for(j = 0; j < linea.n_stazioni - 1; j++)
        {
            u = cerca_stazioni(n, linea.stazioni[j], stazioni);
            v = cerca_stazioni(n, linea.stazioni[j+1], stazioni);

            aggiungi_arco(&g, u, v, 1);
            }
        }

    return g;

}

void stampa_percorso(grafo g, char stazioni[][32], int n, char s[], char d[]) 
{
    int i;
    cammini c[n];
    int start, dest;

    start = cerca_stazioni(n, s, stazioni);
    dest = cerca_stazioni(n, d, stazioni);

    dijkstra(g, start, c);

    i = dest; 

    printf("%s;", stazioni[dest]);

    while(c[i].pred != start)
    {
        printf("%s;", stazioni[c[i].pred]);
        i = c[i].pred;
    }

    printf("%s;", stazioni[start]);
}

struct linea estrai_dati(char s[])
{
    int i = 0;
    int j = 0;
    int k;
    struct linea a;
    char n[32];

    while(s[i] != ' ')
    {
        i++;
    }
    i++;
    while(s[i] != '|')
    {
        n[j] = s[i];
        i++;
        j++;
    }
    n[j] = '\0';
    a.n_stazioni = atoi(n);
    i++;
    j=0;

    for(k = 0; k < a.n_stazioni; k++)
    {
        while(s[i] != '|')
        {
            a.stazioni[k][j] = s[i];
            i++;
            j++; 
        }
        a.stazioni[k][j] = '\0';
        j=0;
        i++;
    }
    return a;
}

int cerca_stazioni(int n_stazioni, char stazione[], char stazioni[][32])
{
    int i;

    for(i = 0; i < n_stazioni; i++)
    {
        if(strcmp(stazione, stazioni[i]) == 0)
            return i;
    }
    return -1;
}

void stampa_pacchi(char nome_file_pacchi[], char stazioni[][32], grafo g, int n_stazioni)
{
    FILE *fp;
    int i = 0;
    int j = 0;
    char s[256];
    struct pacco pacco_corrente;

    char start[32];

    if((fp = fopen(nome_file_pacchi, "r")) == NULL)
    {
        printf("Errore di apertura file\n");
        exit(EXIT_SUCCESS);
    }

    fgets(s, 256, fp);
    while(s[i] != '|') 
    {
        start[j] = s[i];
        i++;
        j++;        
    }
    start[j] = '\0';
    i=0;
    j=0;
    printf("%s\n", start);

    while(fgets(s, 256, fp) != NULL)
    {
        pacco_corrente = estrai_dati_pacchi(s);
        strcpy(pacco_corrente.start, start);
        /*printf("%s %s %s\n", pacco_corrente.nome, pacco_corrente.start, pacco_corrente.dest);*/
        printf("%s:", pacco_corrente.nome);
        stampa_percorso(g, stazioni, n_stazioni, pacco_corrente.dest, pacco_corrente.start);
        printf("\n");
    }

}

struct pacco estrai_dati_pacchi(char s[])
{
    int i = 0;
    int j = 0;
    struct pacco a;

    while(s[i] != ' ')
    {
        a.nome[j] = s[i];
        i++;
        j++;
    }
    a.nome[j] = '-';
    i++;
    j++;
    while(s[i] != '|')
    {
        a.nome[j] = s[i];
        i++;
        j++;
    }
    a.nome[j] = '\0';
    i++;
    j = 0;
    
    while(s[i] != '|')
    {
        a.dest[j] = s[i];
        i++;
        j++; 
    }
    a.dest[j] = '\0';

    return a;
}

void stampa_stazioni(int n_stazioni, char stazioni[][32])
{
    int i;
    for(i = 0; i < n_stazioni; i++)
    {
        printf("%s\n", stazioni[i]);
    }

    return;
}