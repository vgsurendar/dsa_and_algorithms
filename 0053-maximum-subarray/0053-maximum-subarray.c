int maxSubArray(int* nums, int numsSize) {

    int i = 0, sum = nums[0], max_sum = nums[0];

    for (i = 1; i < numsSize; i++) {

        if (sum < 0) {
            sum = nums[i];
        } else {
            sum += nums[i];
        }
        if (sum >= max_sum) {
            max_sum = sum;
        }
    }

    return max_sum;
}