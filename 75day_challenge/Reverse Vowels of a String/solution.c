char* reverseVowels(char* s) {
    int left = 0, right = strlen(s) - 1;
    char temp;

    while (left < right) {
        // Move from left to right
        while (left < right &&
               !(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                 s[left] == 'o' || s[left] == 'u' || s[left] == 'A' ||
                 s[left] == 'E' || s[left] == 'I' || s[left] == 'O' ||
                 s[left] == 'U')) {
            left++;
        }

        // Move from right to left
        while (right > left &&
               !(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                 s[right] == 'o' || s[right] == 'u' || s[right] == 'A' ||
                 s[right] == 'E' || s[right] == 'I' || s[right] == 'O' ||
                 s[right] == 'U')) {
            right--;
        }

        // Swap the vowels
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    return s;
}