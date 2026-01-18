/**
 * Description:
 *   Given an array height[0..n-1] where each element represents a vertical line at that x-coordinate,
 *   find two lines that together with the x-axis form a container that holds the most water
 *   (maximize area = min(height[i],height[j]) * (j-i)).
 *
 * Parameters:
 *   height - array of non-negative integers
 *   n      - number of elements in height
 */

#include <stdio.h>
#include <stdlib.h>
#if 0
/**
 * Finds the maximum area formed between two lines in the height array.
 * Parameters:
 *   height - array of non-negative integers
 *   n      - length of the array
 */
int maxArea(int height[], int n) {
    int left = 0, right = n - 1;
    int max = 0;
    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > max) max = area;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max;
}

int main(void) {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxArea(arr, n);
    printf("Max area: %d\n", result); // expected 49 for this example
    return 0;
}
```// filepath: /Users/ramankumarpandey/rampande/two_pointer_example_2.c
/**
 * Description:
 *   Given an array height[0..n-1] where each element represents a vertical line at that x-coordinate,
 *   find two lines that together with the x-axis form a container that holds the most water
 *   (maximize area = min(height[i],height[j]) * (j-i)).
 *
 * Parameters:
 *   height - array of non-negative integers
 *   n      - number of elements in height
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * Finds the maximum area formed between two lines in the height array.
 * Parameters:
 *   height - array of non-negative integers
 *   n      - length of the array
 */
int maxArea(int height[], int n) {
    int left = 0, right = n - 1;
    int max = 0;
    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > max) max = area;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max;
}
#endif

int maxArea(int *area, int n, int *out_i, int *out_j) {
    
    int max = 0;
    
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            int h = (area[i] < area[j]) ? area[i] : area[j];
            int width = j - i;
            int curr_area = h * width;
            if (curr_area > max) {
                max = curr_area;
                *out_i= i;
                *out_j= j;
            }
        }
    }
    
    return max;
}
int maxArea1(int height[], int n,  int *out_i, int *out_j) {
    int left = 0, right = n - 1;
    int max = 0;
    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > max) {
            max = area;
            *out_i = left;
            *out_j = right;
        }
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max;
}

int main(void) {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index_i, index_j;
    //int result = maxArea(arr, n, &index_i, &index_j);
    int result = maxArea1(arr, n, &index_i, &index_j);

    printf("Max area: %d index_i: %d index_j: %d\n", result, index_i, index_j); // expected 49 for this example
    return 0;
}