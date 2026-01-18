/**
 * Description:
 *   Given a sorted array of integers and a target value, count the number
 *   of unique pairs (i, j) with 0 <= i < j < n such that arr[i] + arr[j] < target.
 *
 * Parameters:
 *   arr    - sorted array of integers (ascending)
 *   n      - number of elements in arr
 *   target - integer threshold
 *
 * Task:
 *   Implement the function:
 *     int countPairsLessThan(int arr[], int n, int target);
 *
 *   The function should return the count of pairs (i, j) where arr[i] + arr[j] < target.
 *
 * Constraints / expectations:
 *   - Time complexity: O(n)
 *   - Space complexity: O(1)
 *   - Array is already sorted; do not sort inside your function.
 *
 * Example:
 *   arr = [1, 2, 3, 4, 5], target = 7
 *   Pairs with sum < 7: (1,2),(1,3),(1,4),(1,5)
 *                       (2,3),(2,4) => count = 6
 *
 * Do not include the solution in this file — only implement the required function when solving.
 */
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[] = {1, 2, 3, 4, 5,8,12};
    int target = 14;
    int unique_pair = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = len-1;
    int sum = 0;
    /* Pair for target less than 14
      (1,2),(1,3),(1,4),(1,5),(1,8),(1,12)
      (2,3),(2,4), (2,5), (2,8)
      (3,4), (3,5), (3,8)
      (4,5),(4,8)
      (5,8)*/
    while(left < right)
    {
      sum = arr[left] + arr[right];
      if (sum < target)
      {
        unique_pair = unique_pair + (right -left);
        left++;
      }
      else
      {
        right--;
      }
    }
    printf("total number of unique pair for which sum is less than taget :%d is %d \n", target,unique_pair);
    return 0;
}
