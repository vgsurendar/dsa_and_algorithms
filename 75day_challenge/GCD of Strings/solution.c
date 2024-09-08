void swap(char** str1, char** str2) {
    char* temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

char* gcdOfStrings(char* str1, char* str2) {

    int len1, len2;

    if (strlen(str1) < strlen(str2)) {
        swap(&str1, &str2);
    }

    len1 = strlen(str1);
    len2 = strlen(str2);

    char* temp1 = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    char* temp2 = (char*)malloc(strlen(str1) + strlen(str2) + 1);

    if (temp1 == NULL || temp2 == NULL) {
        printf("Memory allocation failed!\n");
        return "";
    }

    strcpy(temp1, str1);
    strcat(temp1, str2);

    strcpy(temp2, str2);
    strcat(temp2, str1);

    if (strcmp(temp1, temp2) != 0) {
        free(temp1);
        free(temp2);
        return "";
    }

    free(temp1);
    free(temp2);

    while (len2 != 0) {
        int rem = len1 % len2;
        len1 = len2;
        len2 = rem;
    }

    char* result = (char*)malloc((len1 + 1) * sizeof(char));
    strncpy(result, str1, len1);
    result[len1] = '\0';  // Null-terminate the result
    return result;
}
