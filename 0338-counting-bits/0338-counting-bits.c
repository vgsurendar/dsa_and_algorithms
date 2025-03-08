/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {

    int count = 0;
    int* arr = (int*)malloc((n + 1) * sizeof(int));
    int i = 0, j = 0;
    *returnSize = n + 1;

    for (i = 0; i <= n; i++) {
        count = 0;
        j = i;
        while (j != 0) {
            count += (j & 1);
            j = j >> 1;
        }
        arr[i] = count;
    }

    return arr;
}