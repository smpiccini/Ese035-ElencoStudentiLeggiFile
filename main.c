#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define N 2
// Definisci il tipo di dato struct s_studente
struct s_studente  {
	char nome[MAX_STRLEN+1];
	char cognome[MAX_STRLEN+1];
	unsigned int eta;
	char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    char file[MAX_STRLEN+1];
    int i,j;
    int record_letti;
    FILE *puntafile;
    studente elenco[N];
    
    printf("Inserisci il nome del file: ");
    scanf("%s", file);
    puntafile=fopen(file, "rb");
    if (puntafile == NULL) {
        printf("Impossibile aprire il file.");
    }
    else {
        j=1;
        while(!feof(puntafile)){
            record_letti=fread(elenco,sizeof(studente),N,puntafile);
            for (i=0;i<record_letti;i++){
                printf("Studente %d:\n", j);
                printf("Nome: %s\n", elenco[i].nome);
                printf("Cognome: %s\n", elenco[i].cognome);
                printf("Eta': %d\n", elenco[i].eta);
                printf("Classe: %s\n", elenco[i].classe);
                j++;
                }
            }
    }
        fclose(puntafile);
    return (EXIT_SUCCESS);
}