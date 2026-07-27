#include <stdio.h>

#define N 4
#define TRUE 1

void change_row (int *matrix_pointer, int n, int row, int *new_row);
void change_column (int *matrix_pointer, int n, int column_number, int *new_column);
void change_element (int *matrix_pointer, int n, int *element_index, int new_element);

int main (void) {
     int matrix[N][N] = {0};
     int *matrix_pointer = &matrix[0][0];
     int answer;
     int row_number, new_row[N];
     int column_number, new_column[N];
     int element_index[N], new_element;
     int i, j;

    while (TRUE) {
        printf("Your matrix: (N = %d)\n", N);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%3d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("(1) Change element\n");
        printf("(2) Change row\n");
        printf("(3) Change column\n");
        printf("(4) Exit\n");
        printf("\n");

        printf("-> ");
        scanf("%d", &answer);

        if (answer == 1) {
            printf("Insert the element index (row/column)\nExample: -> 0 1\n");
            printf("-> ");
            for (i = 0; i < 2; i++) {
                scanf("%d", &element_index[i]);
            }

            printf("Insert the new element\n");
            printf("-> ");
            scanf("%d", &new_element);

            change_element (matrix_pointer, N, element_index, new_element);
            printf("Matrix updated.\n");
            printf("\n");

        } else if (answer == 2) {
            printf("Insert the row number (0 to N-1)\n");
            printf("-> ");
            scanf("%d", &row_number);

            printf("Insert the new row\nExample: -> 1 2 ... (N-1)\n");
            printf("-> ");
            for (i = 0; i < N; i++) {
                scanf("%d", &new_row[i]);
            }

            change_row (matrix_pointer, N, row_number, new_row);
            printf("Matrix updated.\n");
            printf("\n");

        } else if (answer == 3) {
            printf("Insert the column number (0 to N-1)\n");
            printf("-> ");
            scanf("%d", &column_number);

            printf("Insert the new column from top to bottom\nExample: -> 1 4 ... (N-1)\n");
            printf("-> ");
            for (i = 0; i < N; i++) {
                scanf("%d", &new_column[i]);
            }

            change_column (matrix_pointer, N, column_number, new_column);
            printf("Matrix updated.\n");
            printf("\n");

        } else if (answer == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;

        } else {
            printf("Invalid answer. Please select a valid answer (1-4).\n");
            printf("\n");
        }
    }

    return 0;
}

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
