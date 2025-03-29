#ifndef  DATI_H
#define DATI_H
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

#define DIM 2
typedef enum Tedificio{CASA,CANTINA,GARAGE}Tedificio;

typedef struct Tacquisto{
    char nomeAcquirente[20];
    unsigned int anno;
    float prezzo;
    Tedificio edificio;
    Tacquisto();
    ~Tacquisto();
    void const stampa();
}Tacquisto;

typedef struct Tnodo {
    Tacquisto dato;
    Tnodo* next;
    Tnodo();
    ~Tnodo();
    Tnodo(Tacquisto a, Tnodo* n);
    void const stampa();
}Tnodo;

void addAcquisto(Tnodo* age[], int dim, Tacquisto a);
void newAcquisto(Tacquisto* a);
void const stampaAgenzie(Tnodo* age[], int dim);
void salvaAcquisti(Tnodo* age[], int dim, Tedificio te);
int random(int min, int max);

#endif