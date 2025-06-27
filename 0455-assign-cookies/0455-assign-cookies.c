int compareInt(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int childIndex = 0;
    int cookieIndex = 0;

    /* Sort greed factors and cookie sizes in ascending order */
    qsort(g, gSize, sizeof(int), compareInt);
    qsort(s, sSize, sizeof(int), compareInt);

    while (cookieIndex < sSize && childIndex < gSize) {
        if (g[childIndex] <= s[cookieIndex]) {
            childIndex++; /* Assign cookie to child */
        }
        cookieIndex++; /* Move to next cookie */
    }

    return childIndex; /* Total children satisfied */
}
