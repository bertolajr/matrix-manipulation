#include "functions.h"

void change_row (int *matrix_pointer, int n, int row_number, int *new_row) {
    int *p, *q = new_row;
    int *row_init = matrix_pointer + (row_number * n);

    for (p = row_init; p < row_init + n; p++) {
        *p = *q++;
    }
}

void change_column (int *matrix_pointer, int n, int column_number, int *new_column) {
    int *p, *q = new_column;
    int *column_init = matrix_pointer + column_number;

    for (p = column_init; p < column_init + (n * n); p += n) {
        *p = *q++;
    }
}

void change_element (int *matrix_pointer, int n, int *element_index, int new_element) {
    int *p = matrix_pointer;
    
    p += *(element_index + 1) + (*element_index * n);
    *p = new_element;
}