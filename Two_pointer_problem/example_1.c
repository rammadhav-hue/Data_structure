/**
 * Description:
 *   Given a sorted array of integers and a target sum, find one pair of indices (i, j)
 *   such that arr[i] + arr[j] == target. Use the two-pointer technique for O(n) time.
 *
 * Parameters:
 *   arr    - sorted array of integers (ascending)
 *   n      - number of elements in arr
 *   target - integer target sum
 *
 * Task:
 *   Implement the function:
 *     int findPairWithSum(int arr[], int n, int target, int *out_i, int *out_j);
 *   Return 1 and set out_i/out_j when a pair is found, otherwise return 0 and set out_i/out_j to -1.
 *
 * Example:
 *   arr = [1, 3, 4, 6, 8, 11], target = 13
 *   One valid pair: indices (2,5) -> values (4,9)  [Note: here actual pair in file is (5,8) -> (5? adjust) use correct values]
 *
 * (The implementation follows below.)
 */

#include <stdio.h>

int findPairWithSum(int arr[], int n, int target, int *out_i, int *out_j) {
 for (int left = 0, right = n - 1; left < right; ) {
     int sum = arr[left] + arr[right];
     if (sum == target) {
         *out_i = left;
         *out_j = right;
         return 1; // Pair found
     } else if (sum < target) {
         left++;
     } else {
         right--;
     }
 }
 *out_i = -1;
 *out_j = -1;
 return 0; // No pair found
}

int main(void) {
    int arr[] = {1, 3, 4, 6, 8, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int t = 13;
    int i, j;
    if (findPairWithSum(arr, n, t, &i, &j))
        printf("Found pair: indices (%d, %d), values (%d, %d)\n", i, j, arr[i], arr[j]);
    else
        printf("No pair found\n");
    return 0;
}