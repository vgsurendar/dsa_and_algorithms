/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int isDigit(char *log) {
    char *p = strchr(log, ' ');
    return isdigit(*(p + 1));
}

int compareLetterLog(const void *a, const void *b) {
    char* log1 = *(char **)a;
    char* log2 = *(char **)b;

    char *c1 = strchr(log1, ' ');
    char *c2 = strchr(log2, ' ');

    int cmp = strcmp(c1,c2);

    if (cmp != 0) {
        return cmp;
    }

    return strcmp(log1, log2);

}

char** reorderLogFiles(char** logs, int logsSize, int* returnSize) {

    char** letterLogs = malloc(logsSize * sizeof(char*));
    char** digitLogs = malloc(logsSize * sizeof(char*));
    char** result = malloc(logsSize * sizeof(char*));

    int l = 0, d = 0, i = 0;

    for (i = 0; i < logsSize; i++) {
        if(isDigit(logs[i])) {
            digitLogs[d++] = logs[i];
        } else {
            letterLogs[l++] = logs[i];
        }
    }

    qsort(letterLogs, l, sizeof(char *), compareLetterLog);

    int idx = 0;

    for (i = 0; i < l; i++) {
        result[idx++] = letterLogs[i]; 
    }

    for (i = 0; i < d; i++) {
        result[idx++] = digitLogs[i];
    }

    *returnSize = logsSize;

    return result;
    
}