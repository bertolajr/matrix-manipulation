#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/***********************************************************************************************************
*    change_row: change the row of the matrix. needs to receive a array with the new numbers               *
************************************************************************************************************/
void change_row (int *matrix_pointer, int n, int row, int *new_row);

/***********************************************************************************************************
*    change_column: change the column of the matrix. needs to receive a array with the new numbers         *
************************************************************************************************************/
void change_column (int *matrix_pointer, int n, int column_number, int *new_column);

/***********************************************************************************************************
*    change_element: change the element of the matrix. needs to receive a integer with the new element     *
************************************************************************************************************/
void change_element (int *matrix_pointer, int n, int *element_index, int new_element);

#endif /* FUNCTIONS_H */