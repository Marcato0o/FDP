#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "coda_priorita_int.h"

nodo_adiacenza* _trova_nodo_adiacente(nodo_adiacenza* t, int vertice) {
    nodo_adiacenza* c = t;
    if (t == NULL)
        return NULL;
    while (c != NULL) {
        if (c->vertice == vertice)
            return c;
        c = c->succ;
    }
    return NULL;
}

nodo_adiacenza* _alloca_nodo_adiacenza(int vertice, float peso) {
    nodo_adiacenza* e = (nodo_adiacenza*)malloc(sizeof(nodo_adiacenza));
    assert(e != NULL);
    e->vertice = vertice;
    e->peso = peso;
    e->succ = NULL;
    return e;
}

void _dealloca_nodo_adiacenza(nodo_adiacenza* e) {
    free(e);
}

nodo_adiacenza* _aggiungi_in_testa_adiacenza(nodo_adiacenza* t, nodo_adiacenza* e) {
    e->succ = t;
    return e;
}

nodo_adiacenza* _togli_nodo_adiacenza(nodo_adiacenza* t, nodo_adiacenza* e) {
    nodo_adiacenza* c = t;
    if (t == NULL)
        return NULL;
    if (t == e)
        return t->succ;
    while (c && c->succ != e)
        c = c->succ;
    if (c != NULL)
        c->succ = e->succ;
    return t;
}

void _elimina_lista_adiacenza(nodo_adiacenza* t) {
    nodo_adiacenza* c = t;
    while (c != NULL) {
        nodo_adiacenza* d = c;
        c = c->succ;
        free(d);
    }
}


grafo crea_grafo(int n, bool diretto) {
    int i;
    grafo g;
    g.n = n;
    g.adiacenti = (nodo_adiacenza**)malloc(n * sizeof(nodo_adiacenza*));
    for (i = 0; i < n; i++)
        g.adiacenti[i] = NULL;
    g.diretto = diretto;
    return g;
}

void aggiungi_arco(grafo* g, int u, int v, float peso) {
    if (_trova_nodo_adiacente(g->adiacenti[u], v) == NULL) { /* l'arco non esiste */
        g->adiacenti[u] = _aggiungi_in_testa_adiacenza(g->adiacenti[u], _alloca_nodo_adiacenza(v, peso));
        if (!g->diretto)
            g->adiacenti[v] = _aggiungi_in_testa_adiacenza(g->adiacenti[v], _alloca_nodo_adiacenza(u, peso));
    }
}

void elimina_arco(grafo* g, int u, int v) {
    nodo_adiacenza* e = _trova_nodo_adiacente(g->adiacenti[u], v);
    if (e != NULL) {
        g->adiacenti[u] = _togli_nodo_adiacenza(g->adiacenti[u], e);
        _dealloca_nodo_adiacenza(e);
        if (!g->diretto) {
            e = _trova_nodo_adiacente(g->adiacenti[v], u);
            assert(e != NULL);
            g->adiacenti[v] = _togli_nodo_adiacenza(g->adiacenti[v], e);
            _dealloca_nodo_adiacenza(e);
        }
    }
}

void elimina_grafo(grafo* g) {
    int i;
    for (i = 0; i < g->n; i++)
        if (g->adiacenti[i] != NULL)
            _elimina_lista_adiacenza(g->adiacenti[i]);
    free(g->adiacenti);
}

void dijkstra(grafo g, int s, cammini c[]) {
    int u, v;
    coda_priorita_int q = crea_coda_priorita_int();
    for (u = 0; u < g.n; u++) {
        c[u].distanza = INFINITY;
        c[u].pred = -1;
    }
    c[s].pred = s;
    c[s].distanza = 0.0;
    for (u = 0; u < g.n; u++)
        enqueue_priorita_int(&q, u, -c[u].distanza); /* La coda è una max-heap */
    while (!empty_priorita_int(q)) {
        nodo_adiacenza* e;
        elemento_coda_priorita_int ep = first_priorita_int(q);
        dequeue_priorita_int(&q);
        u = ep.dato;
        PEROGNI_VICINO(g, u, e, v) {
            if (c[v].distanza > c[u].distanza + e->peso) {
                c[v].distanza = c[u].distanza + e->peso;
                c[v].pred = u;
                aggiorna_priorita_int(&q, v, -c[v].distanza);
            }
        }
    }
}
