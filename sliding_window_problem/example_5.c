/**
 * Description:
 *   Given an array of positive integers and a target sum S, find the minimal length
 *   of a contiguous subarray whose sum is at least S. If no such subarray exists, return 0.
 *
 * Parameters:
 *   arr    - array of positive integers
 *   n      - number of elements in arr
 *   target - integer target sum S (positive)
 *
 * Task:
 *   Implement the function:
 *     int minSubArrayLen(int target, int arr[], int n);
 *
 * Constraints / expectations:
 *   - Time complexity: O(n)
 *   - Space complexity: O(1)
 *   - All array elements are positive (this allows the two-pointer / sliding-window approach).
 *
 * Example:
 *   arr = [2, 3, 1, 2, 4, 3], target = 7
 *   Minimal subarray with sum >= 7 is [4, 3] -> length = 2, so return 2.
 *
 * Additional examples:
 *
 * 1) Single-element satisfies target:
 *    arr = [1, 1, 1, 1], target = 1
 *    Minimal subarray -> [1] -> length = 1
 *
 * 2) No valid subarray:
 *    arr = [1, 1, 1, 1], target = 10
 *    Sum of whole array = 4 < 10 -> return 0
 *
 * 3) Entire array required:
 *    arr = [1, 2, 3, 4, 5], target = 15
 *    Sum of all elements = 15 -> length = 5
 *
 * 4) Minimal subarray in the middle:
 *    arr = [5, 1, 3, 5, 10, 7, 4, 9, 2], target = 15
 *    One minimal subarray is [10, 7] -> length = 2
 *
 * 5) Multiple candidates, choose shortest:
 *    arr = [1, 2, 3, 4, 5], target = 11
 *    Smallest subarray with sum >= 11 is [3,4,5] -> length = 3
 */