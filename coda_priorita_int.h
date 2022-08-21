#ifndef CODA_PRIORITA_INT_H
#define CODA_PRIORITA_INT_H

#include <stdbool.h>

typedef struct {
    int dato;
    float priorita;
} elemento_coda_priorita_int;

typedef struct {
    elemento_coda_priorita_int* dati;
    int capacita;
    int elementi;
} coda_priorita_int;

coda_priorita_int crea_coda_priorita_int(void);
void elimina_coda_priorita_int(coda_priorita_int* q);
void enqueue_priorita_int(coda_priorita_int* q, int dato, float priorita);
void dequeue_priorita_int(coda_priorita_int* q);
elemento_coda_priorita_int first_priorita_int(coda_priorita_int q);
bool empty_priorita_int(coda_priorita_int q);
void stampa_coda_priorita_int(coda_priorita_int q);
void aggiorna_priorita_int(coda_priorita_int* q, int dato, float npriorita);

#endif /* CODA_PRIORITA_INT_H */

