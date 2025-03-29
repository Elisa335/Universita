#include "dati.h"

int main() {

    srand(time(0));

    Tnodo* agenzia[DIM];
    for (int i = 0; i<DIM; i++) {
        agenzia[i] = new Tnodo(); //il puntatore ora punta ad una struttura Tnodo nell'heap
    }
    Tacquisto a;
    for (int i = 0; i<5; i++) {
        newAcquisto(&a);
        addAcquisto(agenzia, DIM, a);
    }

    stampaAgenzie(agenzia, DIM);
    salvaAcquisti(agenzia, DIM, CASA);
    stampaAgenzie(agenzia,DIM);

    for (int i = 0; i<DIM; i++) {
        delete agenzia[i];
    }
    delete[] agenzia;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.