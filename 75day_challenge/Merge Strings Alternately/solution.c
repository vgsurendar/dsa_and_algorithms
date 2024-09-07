char* mergeAlternately(char* word1, char* word2) {
    int i = 0, k = 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int total_len = len1 + len2 + 1;

    char* new_word = (char*)malloc(total_len * sizeof(char));

    if (new_word == NULL) {
        printf("malloc failed !\n");
        return NULL;
    }

    for (i = 0; i < len1 || i < len2; i++) {

        if (i < len1) {
            new_word[k++] = word1[i];
        }

        if (i < len2) {
            new_word[k++] = word2[i];
        }
    }

    new_word[k] = '\0';

    return new_word;
}
