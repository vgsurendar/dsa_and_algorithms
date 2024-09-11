bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i = 0;

    for (i = 0; i < flowerbedSize; i++) {
        /* Check if current(i) plot &&  immediate left(i -1) plot && immediate
         * right(i+1) plot are empty (or out of bound)*/
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == (flowerbedSize - 1) || flowerbed[i + 1] == 0)) {

            /* Plant the flower */
            flowerbed[i] = 1;
            n--;
        }

        /* If all n plants planted, return TRUE */
        if (n == 0) {
            return 1;
        }
    }

    /* If we finish the loop and haven't planted all flowers, return FALSE */
    return n <= 0;
}