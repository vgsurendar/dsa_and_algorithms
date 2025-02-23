double findMaxAverage(int* nums, int numsSize, int k) {
    int i = 0, j = 0;
    double avg = 0, max_avg = 0, sum = 0;

    for(i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    max_avg = sum / k ;

    while(j < (numsSize - k)) {

        sum = sum + nums[j + k] - nums[j];
        avg = sum / k;

        if(avg >= max_avg) {
            max_avg = avg;
        }

        j++;
    }

    return max_avg;
    
}