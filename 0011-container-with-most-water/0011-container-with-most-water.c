int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = (heightSize - 1);
    int area = 0;
    int max_area = 0;
    int min_height = 0;
    int width = 0;

    while (left < right) {
        min_height = (height[left] < height[right]) ? height[left] : height[right];
        width = (right - left);
        area = min_height * width;

        if (area > max_area) {
            max_area = area;
        }

        if(height[left] < height[right]) {
            left ++;
        } else {
            right --;
        }
    }

    return max_area;
}