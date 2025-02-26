bool isNum(char s) {
    if (s >= '0' && s <= '9') {
        return true;
    }
    return false;
}
char* clearDigits(char* s) {
    int i = 0, j = 0;
    int len = strlen(s);

    char* newStr = (char*)malloc(len + 1);

    for (i = 0; i < len; i++) {
        if (isNum(s[i]) == true) {
            if (j > 0) {
                j--;
            }
        } else {
            newStr[j] = s[i];
            j++;
        }
    }
    newStr[j] = '\0';
    return newStr;
}