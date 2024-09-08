/* Find Max value in the array */
int findMaxofArray(int* arr, int size) {
    int max = arr[0];
    int i = 0;

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int i = 0;
    int maxCandy = 0;
    *returnSize = candiesSize;

    bool* result = (bool*)malloc(candiesSize * sizeof(bool));

    maxCandy = findMaxofArray(candies, candiesSize);

    for (i = 0; i < candiesSize; i++) {
        if ((candies[i] + extraCandies) >= maxCandy) {
            result[i] = 1;
        }
        else {
            result[i] = 0;
        }
    }

    return result;
}
