#include <stdio.h>
#include <stdlib.h>

#define MAX_NAMES_LEN 50

void createNames(char ***names, int cant_names);
void showNames(char **names, int cant_names);

int main() {
    char **names;
    int cant_names;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cant_names); fflush(stdin);

    createNames(&names, cant_names);

    for (int i = 0; i < cant_names; i++) {               //Cargar nombres
        printf("Cargar nombre %d: ", i+1);
        gets(names[i]);
    }

    showNames(names, cant_names);

    return 0;
}

void createNames(char ***names, int cant_names) {
    *names = (char **)malloc(cant_names*sizeof(int *));

    for (int i = 0; i < cant_names; i++) {
        (*names)[i] = (char *)malloc(MAX_NAMES_LEN*sizeof(int));
    }
}

void showNames(char **names, int cant_names) {
    for (int i = 0; i < cant_names; i++) {
        printf("Nombre %d: %s\n", i+1, names[i]);
    }
}