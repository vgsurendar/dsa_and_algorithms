void reverse (char* s, int start, int end) {
    int i = 0;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++ ;
        end-- ;
    }
}

char* removeUnwantedSpaces (char* s) {
    int i = 0, j = 0;
    int len = strlen(s);

    char* res = (char*)malloc((len + 1) * sizeof(char));

    while (s[i] == ' ') {
        i++ ;
    }

    while (s[i]) {
        if (s[i] != ' ') {
            res[j++] = s[i++];
        } else {
            res[j++] = ' ';
            while (s[i] == ' ') {
                i++;
            }
        }
    }

    while ((j > 0) && res[j - 1] == ' ' ) {
        j --;
    }

    res[j] = '\0';

    return res;
}
char* reverseWords(char* s) {
    int i = 0, start = 0;
    int len = strlen(s);
    char *res = NULL;
    start = 0;
    while (s[start] == " ") {
        start++ ;
    }

    reverse(s, start, len - 1);

    for (i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    res = removeUnwantedSpaces(s);

    return res;
}