#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define YEAR 5
#define MONTH 12
#define MIN_VAL 10000
#define MAX_VAL 50000
#define NN 164
#define MATRIX_PROFIT_ELEMENTS 3
#define PROFIT_ELEMENT 0
#define YEAR_ELEMENT 1
#define MONTH_ELEMENT 2

void loadMatrix(int matrix[YEAR][MONTH]);
void showMatrix(int matrix[YEAR][MONTH]);
float annualProfit(int matrix[YEAR][MONTH], int year);
void profitRange(int matrix[YEAR][MONTH], int *map_matrix, int *mip_matrix);

int main() {
    int matrix_control[YEAR][MONTH];
    int *max_profit_matrix = (int *)malloc(MATRIX_PROFIT_ELEMENTS*sizeof(int));
    int *min_profit_matrix = (int *)malloc(MATRIX_PROFIT_ELEMENTS*sizeof(int));

    loadMatrix(matrix_control);
    showMatrix(matrix_control);

    for (int i = 0; i < YEAR; i++) {
        printf("Ganancia a%co %d: %.2f\n", NN, i+1, annualProfit(matrix_control, i));
    }

    profitRange(matrix_control, max_profit_matrix, min_profit_matrix);

    printf("Valor maximo: %d. A%co: %d, Mes: %d\n", max_profit_matrix[PROFIT_ELEMENT], NN, max_profit_matrix[YEAR_ELEMENT]+1, max_profit_matrix[MONTH_ELEMENT]+1);
    printf("Valor minimo: %d. A%co: %d, Mes: %d\n", min_profit_matrix[PROFIT_ELEMENT], NN, min_profit_matrix[YEAR_ELEMENT]+1, min_profit_matrix[MONTH_ELEMENT]+1);

    return 0;
}

void loadMatrix(int matrix[YEAR][MONTH]) {
    srand(time(NULL));

    for (int i = 0; i < YEAR; i++) {
        for (int j = 0; j < MONTH; j++) {
            matrix[i][j] = rand()%(MAX_VAL-MIN_VAL) + MIN_VAL + 1;
        }
    }
}

void showMatrix(int matrix[YEAR][MONTH]) {
    for (int i = 0; i < YEAR; i++) {
        printf("[");

        for (int j = 0; j < MONTH; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\b]\n");
    }
}

float annualProfit(int matrix[YEAR][MONTH], int year) {
    int sum=0;

    for (int i = 0; i < MONTH; i++) {
        sum += matrix[year][i];
    }

    return ((float)sum/MONTH);
}

void profitRange(int matrix[YEAR][MONTH], int *map_matrix, int *mip_matrix) {
    map_matrix[PROFIT_ELEMENT] = 0;
    mip_matrix[PROFIT_ELEMENT] = MAX_VAL+1;

    for (int i = 0; i < YEAR; i++) {
        for (int j = 0; j < MONTH; j++) {
            if (matrix[i][j] > map_matrix[PROFIT_ELEMENT]) {
                map_matrix[PROFIT_ELEMENT] = matrix[i][j];
                map_matrix[YEAR_ELEMENT] = i;
                map_matrix[MONTH_ELEMENT] = j;
            }

            if (matrix[i][j] < mip_matrix[PROFIT_ELEMENT]) {
                mip_matrix[PROFIT_ELEMENT] = matrix[i][j];
                mip_matrix[YEAR_ELEMENT] = i;
                mip_matrix[MONTH_ELEMENT] = j;
            }
        }
    }
}