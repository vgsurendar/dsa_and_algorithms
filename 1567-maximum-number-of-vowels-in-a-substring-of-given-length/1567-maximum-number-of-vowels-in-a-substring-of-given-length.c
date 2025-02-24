#define TRUE 1
#define FALSE 0

bool isVowel(char s) {
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
        return TRUE;
    }
    return FALSE;
}

int maxVowels(char* s, int k) {
    int i = 0;
    int len = strlen(s);
    int count = 0, max_count = 0;

    for(i = 0; i < k; i++) {
        if(isVowel(s[i]) == TRUE) {
            count++ ;
        }
    }

    max_count = count;

    for(i = 0; i <= len - k; i++) {
        if(isVowel(s[i]) == TRUE) {
            count --;
        }
        if(isVowel(s[i+k]) == TRUE) {
            count ++;
        }
        if(count > max_count) {
            max_count = count;
        } 
    }

    return max_count;
}