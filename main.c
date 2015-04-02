#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define N 2
#define MAX_STRLEN 30
#define MAX_FNAMELEN 255

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente elenco[N];
    int letti, i;
    FILE *inf;
    char fileName[MAX_FNAMELEN+1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    inf = fopen(fileName, "rb");
    if(inf == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s in lettura\n", fileName);
        exit(1);
    }
    
    letti = fread(elenco, sizeof(studente), N, inf);
    /* La precedente chiamata di fread legge _al massimo_ N record, se disponibili
       nel file. Il numero di record effettivamente letto è riportato in letti*/
    while(letti) {
        printf("Letti %d record\n", letti);
        for(i=0; i<letti; i++) {
            printf("%s; %s; %d; %s\n", 
                elenco[i].nome,
                elenco[i].cognome,
                elenco[i].eta,
                elenco[i].classe);
        }
        letti = fread(elenco, sizeof(studente), N, inf);
    }
    fclose(inf);
    
    return (EXIT_SUCCESS);
}