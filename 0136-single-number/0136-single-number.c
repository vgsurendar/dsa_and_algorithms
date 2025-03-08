int singleNumber(int* nums, int numsSize) {

    int theOne = 0, i = 0;

    while(i < numsSize) {
        theOne ^= nums[i];
        i++;
    }

    return theOne;    
}