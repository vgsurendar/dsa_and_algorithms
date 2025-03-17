#define MAX_NUM 501
bool divideArray(int* nums, int numsSize) {
    int hashmap[MAX_NUM] = {0};
    int i = 0;

    for (i = 0; i < numsSize; i++) {
        hashmap[nums[i]]++ ;
    }

    for (i = 0; i < MAX_NUM; i++) {
        if(hashmap[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}