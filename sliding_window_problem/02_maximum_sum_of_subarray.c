/****************************************************************
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.
Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ k ≤ arr.size()
*******************************************************************/

#include <stdio.h>

long long maxSubArrSum(int *arr, int len, int subArrLen)
{
  if (subArrLen <= 0 || len <= 0 || subArrLen > len)
    return 0;

  long long sum = 0;
  long long maxSum = 0;

  // compute first window sum
  for (int j = 0; j < subArrLen; ++j) {
    sum += arr[j];
  }
  maxSum = sum;

  for (int i = 1; i <= len - subArrLen; ++i) {
    sum = sum - arr[i-1] + arr[i+subArrLen-1];
    if (sum > maxSum)
      maxSum = sum;
  }
  return maxSum;
}

int main()
{
  int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int len = sizeof(arr)/sizeof(arr[0]);
  int subArrSize = 4;
  long long maxSum = maxSubArrSum(arr, len, subArrSize);
  printf("Max sum of subArray of length %d will be %lld\n", subArrSize, maxSum);

  return 0;
}
