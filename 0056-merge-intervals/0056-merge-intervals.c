/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#define COLUMN_SIZE 2

int compare(const void* a, const void* b) {
    /* Return (a[0][0] - b[0][0]) */
    return (*(*((int**)a + 0) + 0) - *(*((int**)b + 0) + 0));
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int index = 0, i = 0;

    /* Sort the intervals based on start value intervals[i][0] */
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    /* Create 2D Array for storing result */
    int** result = (int**)malloc(intervalsSize * sizeof(int*));

    /* Allocate memory for the 1D Array that stores column size value for each
     * index in the result array */
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    /* Store the first entry in interval array to the result array */
    result[index] = (int*)malloc(COLUMN_SIZE * sizeof(int));
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];

    /*The column array will be having all values as 2 since there is no change
    in column size Eg: [2,2,2,2,... upto (returnSize - 1)]*/
    (*returnColumnSizes)[index] = COLUMN_SIZE;

    for (i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[index][1]) {
            /* Update result[index][1] if it's less than intervals[i][0]*/
            result[index][1] =
                (intervals[i][1] > result[index][1] ? intervals[i][1]
                                                    : result[index][1]);
        } else {
            /* Update the result with the entry from intervals itself */
            index++;
            result[index] = (int*)malloc(COLUMN_SIZE * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = COLUMN_SIZE;
        }
    }

    *returnSize = index + 1;
    return result;
}