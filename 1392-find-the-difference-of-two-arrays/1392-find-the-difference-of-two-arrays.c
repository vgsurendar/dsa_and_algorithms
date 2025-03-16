/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#define MAX_SIZE 2001 //(-999 to 0 to +999)
#define OFFSET 1000
#define PRESENT 1
#define NOT_PRESENT 0

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {

    int hashmap1[MAX_SIZE] = {0}, hashmap2[MAX_SIZE] = {0};
    int i = 0;
    int count1 = 0, count2 = 0;

    /* Create Hashmap for the entries in nums1 & nums2.
       Mark entries in the arrays as present in HashMap of the same index */

    for (i = 0; i < nums1Size; i++) {
        hashmap1[nums1[i] + OFFSET] = PRESENT;
    }

    for (i = 0; i < nums2Size; i++) {
        hashmap2[nums2[i] + OFFSET] = PRESENT;
    }

    /* Allocate memory for the 2D result array
    Eg: reult[0] = [1,3] result[1] = [4,6] */
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(nums1Size * sizeof(int));
    result[1] = (int*)malloc(nums2Size * sizeof(int));

    /* Update returnColumnSize array
       The array will be like {2,2} which holds the size of output entries
       {1,3}, {4,6} respectively */
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));

    /* Find elements in nums1 but not in nums2 */
    for (i = 0; i < nums1Size; i++) {
        if (hashmap1[nums1[i] + OFFSET] == PRESENT &&
            hashmap2[nums1[i] + OFFSET] == NOT_PRESENT) {
            result[0][count1++] = nums1[i];

            /* Remove Duplicate entry to result */
            hashmap1[nums1[i] + OFFSET] = NOT_PRESENT; 
        }
    }

    /* Find elements in nums2 but not in nums1 */
    for (i = 0; i < nums2Size; i++) {
        if (hashmap2[nums2[i] + OFFSET] == PRESENT &&
            hashmap1[nums2[i] + OFFSET] == NOT_PRESENT) {
            result[1][count2++] = nums2[i];
            /* Remove Duplicate entry to result */
            hashmap2[nums2[i] + OFFSET] = NOT_PRESENT;
        }
    }

    /* Update returnColumnSizes array size */
    (*returnColumnSizes)[0] = count1;
    (*returnColumnSizes)[1] = count2;
    *returnSize = 2;

    return result;
}