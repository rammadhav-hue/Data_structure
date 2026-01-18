
/**
 * Description:
 *   Given a sorted array of integers (ascending) and an integer k >= 0,
 *   count the number of pairs (i, j) with 0 <= i < j < n such that
 *   abs(arr[i] - arr[j]) == k.
 *
 * Parameters:
 *   arr - sorted array of integers (may contain duplicates)
 *   n   - number of elements in arr
 *   k   - non-negative integer target difference
 *
 * Task:
 *   Implement the function:
 *     int countPairsWithDiffK(int arr[], int n, int k);
 *
 *   The function should return the count of index-pairs (i, j) where
 *   arr[j] - arr[i] == k (since array is sorted, this is equivalent to abs).
 *
 * Constraints / expectations:
 *   - Time complexity: O(n)
 *   - Space complexity: O(1)
 *   - Array is already sorted; do not sort inside your function.
 *
 * Example:
 *   arr = [1, 3, 4, 6, 8, 9], k = 5
 *   Valid pairs (by value): (1,6), (3,8), (4,9)  => count = 3
 *
 * Do not include the solution in this file — only implement the required function when solving.
 */

#include <stdio.h>
#include <stdlib.h>


int countPairsWithDiffK(int arr[], int n, int k)
{
  int count = 0;
  int left = 0;
  int right = 0;

  while (right < n)
  {
    int absDiff = arr[right] - arr[left];
    if (absDiff == k)
    {
      printf("Valid pair is (%d, %d)\n", arr[left], arr[right]);
      count++;
      left++;
      right++;
    }
    else if (absDiff < k)
    {
      right++;
    }
    else
    {
      left++;
      if (left == right)
      {
        right++;
      }
    }
  }
  return count;
}
int main()
{
  int arr[] = {1,3,4,6,8,9};
  int absDiff = 5;
  int len = sizeof(arr)/sizeof(arr[0]);
  int count = countPairsWithDiffK(arr, len, absDiff);
  printf("Total number of Valid pairs whose absolute difference %d  is %d\n",absDiff,count);
  return 0;
}