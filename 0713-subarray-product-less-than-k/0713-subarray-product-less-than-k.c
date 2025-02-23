int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int i = 0, j = 0, prod = 1, count = 0;
    while (j < numsSize) {
        prod *= nums[j];
        while ((prod >= k) && (i <= j)) {
            if (nums[i] != 0) {
                prod /= nums[i];
            }
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}
