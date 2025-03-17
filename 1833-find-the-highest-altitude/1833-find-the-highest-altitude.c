int largestAltitude(int* gain, int gainSize) {

    int i = 0;
	int alt_size = gainSize + 1;
    int* alt = (int *)malloc(alt_size * sizeof(int));
    int largest_alt = 0;
    alt[0] = 0;

    for (i = 1; i < alt_size; i++) {
        alt[i] = gain[i-1] + alt[i-1];
    }

    for (i = 0; i < alt_size; i++) {
        largest_alt = largest_alt >= alt[i] ? largest_alt : alt[i];
    }

    free(alt);
    return largest_alt;
}