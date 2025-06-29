int minBitFlips(int start, int goal) {

    int flips = 0;
    int start_bit = 0, goal_bit = 0;

    while ((start != 0) || (goal != 0)) {
        start_bit = start & 1;
        goal_bit = goal & 1;

        start = start >> 1;
        goal = goal >> 1;

        if (start_bit != goal_bit) {
            flips ++;
        }
    }

    return flips;
}