int missingNumber(int* nums, int numsSize) {

    int expected_sum = ((numsSize * (numsSize + 1)) / 2);
    int sum = 0, i = 0;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return (expected_sum - sum);
}