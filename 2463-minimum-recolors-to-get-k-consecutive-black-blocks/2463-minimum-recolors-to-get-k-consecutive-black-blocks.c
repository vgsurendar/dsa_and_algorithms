int minimumRecolors(char* blocks, int k) {
    int i = 0;
    int len = strlen(blocks);
    int count = 0, min_count = 0;

    for(i = 0; i < k; i++) {
        if(blocks[i] == 'W') {
            count++;
        }
    }
    min_count = count;

    for (i = 1; i <= (len - k); i++) {
        if(blocks[i - 1] == 'W') {
            count --;
        }
        if (blocks[i + k - 1] == 'W') {
            count ++;
        }
        if (count < min_count) {
            min_count = count;
        }
    }

    return min_count;
}