void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void moveZeroes(int* nums, int numsSize) {

    int i = 0, j = 0;

    for (j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {
            if (i != j) {
                swap(&nums[i], &nums[j]);
            }
            i++;
        }
    }
}