/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    int row = 0, col = 0;

    /* Create a 2D Array Pointer for result */
    int** result = (int**)malloc(numRows * sizeof(int*));

    /* Allocate memory for returnColumnSizes also */
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    /* Allocate column wise memory for the result array */
    for (row = 0; row < numRows; row++) {
        result[row] = (int*)malloc((row + 1) * sizeof(int));
        (*returnColumnSizes)[row] = (row + 1); /* Update number of columns per row */

        /* The first and last entry in each row will be 1 */
        result[row][0] = 1;
        result[row][row] = 1;

        /* Update Remanining entries */
        for (col = 1; col < row; col++) {
            result[row][col] = result[row -1][col -1] + result[row-1][col];
        }
    }

    *returnSize = numRows;
    return result;
}