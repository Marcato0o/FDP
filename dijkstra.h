#ifndef _GRAFI_H
#define _GRAFI_H

#include <stdbool.h>

typedef struct _nodo_adiacenza {
    int vertice;
    float peso;
    struct _nodo_adiacenza* succ;
} nodo_adiacenza;

typedef struct {
    int n;
    nodo_adiacenza **adiacenti;
    bool diretto;
} grafo;

#define PEROGNI_VICINO(g, u, e, v) \
for (e = g.adiacenti[u], v = (e != NULL ? e->vertice : -1); e != NULL; e = e->succ, v = (e != NULL ? e->vertice : -1))


grafo crea_grafo(int n, bool diretto);
void aggiungi_arco(grafo* g, int u, int v, float peso);
void elimina_arco(grafo* g, int u, int v);
void elimina_grafo(grafo* g);

typedef struct {
    float distanza;
    int pred;
} cammini;

void dijkstra(grafo g, int s, cammini c[]);

#endif
