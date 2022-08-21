#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 15

void aggiungi_navi(int n, int campo[DIM_MAX][DIM_MAX]);
int cerca_lunghezza(char tipo_nave[64]);
int piazza_nave(int lunghezza, int x,int y, int orientamento, int campo[DIM_MAX][DIM_MAX],int dim);
void stampa_campo(int n, int campo[DIM_MAX][DIM_MAX]);
int cerca_or(char orientamento);
void inizializza_matrice(int dim, int matrice[DIM_MAX][DIM_MAX]);
int controlla_campo(int lunghezza, int x, int y, int or, int campo[DIM_MAX][DIM_MAX], int n)

int main()
{
    int campo[DIM_MAX][DIM_MAX];

    inizializza_matrice(DIM_MAX, campo);

    aggiungi_navi(DIM_MAX, campo);

    stampa_campo(DIM_MAX, campo);

    return EXIT_SUCCESS;
}

void aggiungi_navi(int n, int campo[][DIM_MAX])
{
    int x,y,or;
    char tipo_nave[64];
    char direzione;
    int lunghezza, error_check;

    while ((scanf ("%s %d %d %c", tipo_nave, &x, &y, &direzione)) != EOF)
    {
        
        lunghezza = cerca_lunghezza(tipo_nave);

        if((or = cerca_or(direzione)) == -1)
            printf("orientamento sconosciuto : %c\n", direzione);

        if(lunghezza == -1)
            printf("tipo di nave sconosciuto: %s\n", tipo_nave);

        if(controlla_campo(lunghezza, x, y, or, campo, n) == 1);
            printf("errore di caricamento della nave: %s %d %d %c\n", tipo_nave, x, y, direzione);
        else
            piazza_nave(lunghezza, x, y, or, campo, n);
    }
}

int cerca_lunghezza(char tipo_nave[])
{
    if(strcmp(tipo_nave, "portaerei") == 0)
        return 5;
    if(strcmp(tipo_nave, "cacciatorpediniere") == 0)
        return 4;
    if(strcmp(tipo_nave, "incrociatore") == 0)
        return 3;
    if(strcmp(tipo_nave, "ricognitore") == 0)
        return 2;

    return -1;
}

int piazza_nave(int lunghezza, int x,int y, int orientamento, int campo[][DIM_MAX],int dim)
{

}

void stampa_campo(int n, int campo[][DIM_MAX])
{
    int i,j,k;

    for(i = n-1; i >= 0; i--)
    {
        printf("%2d ", i);

        for(j = 0; j < n; j++)
        {
            if(campo[i][j] == 1)
                printf(" * ");
            if(campo[i][j] == 0)
                printf("   ");    
        }

        printf("\n");
    }

    printf("   ");
    for(k = 0; k < n; k++)
    {
        printf("%2d ",k);
    }
}

int cerca_or(char orientamento)
{
    if(orientamento == 'O')
        return 1;
    if(orientamento == 'V')
        return 0;

    return -1;
}

void inizializza_matrice(int dim, int matrice[][DIM_MAX])
{
    int i,j;
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
            matrice[i][j] = 0;
    }

    return;
}


int controlla_campo(int lunghezza, int x, int y, int or, int campo[][DIM_MAX], int n)
{
    int i;
    for(i = 0; i < lunghezza; i++)
    {
        if(or == 0)
        {
            if(campo[x+i][y] == 1)
                return 1;
        }
        
        if(or == 1)
        {
            if(campo[x][y-i] == 1)
                return 1;
        }     
    }
    return 0;
}


