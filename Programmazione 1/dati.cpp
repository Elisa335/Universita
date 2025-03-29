#include "dati.h"

    Tacquisto::Tacquisto() {
        nomeAcquirente[0] = '\0';
        anno = 2000;
        prezzo = 50;
        edificio = CASA;
    }

    Tacquisto::~Tacquisto() {
    }

    void const Tacquisto::stampa() {
    string edificio_string;
        switch (edificio) {
            case 0: edificio_string = "CASA";
                break;
            case 1: edificio_string = "CANTINA";
                break;
            case 2: edificio_string = "GARAGE";
                break;
            default: printf("N/D");
        }

        printf("%s(%s) ANNO costruzione=%d prezzo=%.2f", nomeAcquirente, edificio_string.c_str(), anno, prezzo);
    }

    Tnodo::Tnodo() {
        dato = Tacquisto();
        next = NULL;
    }

    Tnodo::Tnodo(Tacquisto a, Tnodo* n) {
        dato = a;
        next = n;
    }

    Tnodo::~Tnodo() {
    }


    void const Tnodo::stampa() {
        dato.stampa();
    }

    int random(int min, int max) {
        return rand()%(max-min+1)+min;
    }

void newAcquisto(Tacquisto* a) {
        a->edificio = (Tedificio)random(0,2);
        do {
            printf("Inserisci un anno tra 1950 e 2023\n");
            scanf("%d", &(a->anno));
        }while (a->anno<1950 || a->anno>2023);

        a->prezzo = (float)random(5000000, 14999999)/100;
        printf("Inserisci il tuo nome: \n");
        scanf("%19s", a->nomeAcquirente); //evito buffer overflow
        }

void addAcquisto(Tnodo* age[], int dim, Tacquisto a) {
        if (dim==0) {
            printf("Le liste sono vuote!\n");
            return;
        }
        int x = random(0,dim);
        Tnodo* tmp = age[x];
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new Tnodo(a, NULL);
    }

void const stampaAgenzie(Tnodo* age[], int dim) {
        if (dim==0) {
            printf("Le liste sono vuote!\n");
            return;
        }
        for (int i = 0; i<dim; i++) {
            Tnodo* tmp = age[i];
            while (tmp->next != NULL) {
                tmp->dato.stampa();
                tmp = tmp->next;
            }
        }
    }

void salvaAcquisti(Tnodo* age[], int dim, Tedificio te) {
        if (dim==0) {
            printf("Le liste sono vuote!\n");
            return;
        }
        string nomeFile;
        switch (te) {
            case 0: {nomeFile = "acquistiCasa.txt"; }
            break;
            case 1: nomeFile = "acquistiCantina.txt";
            break;
            case 2: nomeFile = "acquistiGarage.txt";
            break;
            default: printf("N/D");
        }

        FILE* f = fopen(nomeFile.c_str(), "w");
        if (!f) {
            printf("C'è stato un'errore nella lettura del file!\n");
            return;
        }

        for (int i = 0; i<dim; i++) {
            Tnodo* tmp = age[i];
            while (tmp!= NULL) {
                if (tmp->dato.edificio == te) {
                    fprintf(f,"%s ANNO costruzione=%d prezzo=%.2f\n", tmp->dato.nomeAcquirente, tmp->dato.anno, tmp->dato.prezzo);
                }
                tmp = tmp->next;
            }
            age[i] = tmp;
        }

        fclose(f);
    }


