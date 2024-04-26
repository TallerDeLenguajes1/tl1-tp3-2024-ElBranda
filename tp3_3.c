#include <stdio.h>
#include <stdlib.h>

#define NAMES 5
#define MAX_NAMES_LEN 50

void createNames(char ***names);
void showNames(char **names);

int main() {
    char **names;

    createNames(&names);

    for (int i = 0; i < NAMES; i++) {               //Cargar nombres
        printf("Cargar nombre %d: ", i+1);
        gets(names[i]);
    }

    showNames(names);

    return 0;
}

void createNames(char ***names) {
    *names = (char **)malloc(NAMES*sizeof(int *));

    for (int i = 0; i < NAMES; i++) {
        (*names)[i] = (char *)malloc(MAX_NAMES_LEN*sizeof(int));
    }
}

void showNames(char **names) {
    for (int i = 0; i < NAMES; i++) {
        printf("Nombre %d: %s\n", i+1, names[i]);
    }
}