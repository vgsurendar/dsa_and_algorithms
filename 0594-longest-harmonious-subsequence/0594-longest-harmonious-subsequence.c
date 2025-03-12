int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int findLHS(int* nums, int numsSize) {
    int i = 0, j = numsSize - 1;
    int length = 0, maxlength = 0;
    int start = 0, end = 0;

    if (numsSize == 0) {
        return 0;
    }

    /* Quick Sort Elements */
    qsort(nums, numsSize, sizeof(int), compare);

    start = 0;
    end = 1;

    /* Find harmonious array */
    while(end < numsSize) {

        if(nums[end] - nums[start] > 1) {
            start++;
        }

        if(nums[end] - nums[start] == 1) {
            length = end - start + 1;
            maxlength = length > maxlength ? length : maxlength;
        }

        end++;
    }

    return maxlength;
    
}