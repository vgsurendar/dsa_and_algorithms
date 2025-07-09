int num (char s) {
    switch (s) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }

    return 0;
}

int romanToInt(char* s) {

    int sum = 0;
    int i = 0;
    int curr = 0, next = 0;

    while (s[i] != '\0') {

        curr = num(s[i]);
        next = num(s[i+1]);

        if (curr < next) {
            sum += (next - curr);
            i += 2;
        } else {
            sum += curr;
            i += 1;
        }
    }

    return sum;
}