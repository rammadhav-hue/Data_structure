/**
 * Description:
 *   Given an array of integers and a fixed window size of 3, find the maximum sum
 *   of any contiguous subarray of length 3.
 *
 * Parameters:
 *   arr - input array of integers
 *   n   - number of elements in arr
 *
 * Task:
 *   Describe or implement a function with signature:
 *     int maxSumWindowK(int arr[], int len, int windowSize);
 *   that returns the maximum sum of any contiguous subarray of length 3.
 *   If n < 3, define the function to return an appropriate value (e.g., 0 or handle as invalid).
 *
 * Example:
 *   arr = [1, 4, 2, 10, 23, 3, 1, 0, 20]
 *   index  0, 1, 2, 3,  4,  5, 6, 7, 8    
 *   All contiguous subarrays of length 3:
 *     [1,4,2] -> 7
 *     [4,2,10] -> 16
 *     [2,10,23] -> 35
 *     [10,23,3] -> 36
 *     [23,3,1] -> 27
 *     [3,1,0] -> 4
 *     [1,0,20] -> 21
 *   Maximum sum for window size 3 is 36 (subarray [10,23,3]).
 *
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>

 int maxSumWindowK(int arr[], int len, int windowSize)
 {
   
   int sum = 0;
   int maxSum = 0;
   for (int i = 0; i <= len - windowSize; i++)
   {
     
     if (i == 0)
     {
       for (int k =0; k < windowSize; k++)
       {
         sum += arr[k];
       }
       maxSum = sum;
     }
     else
     {
       sum = sum-arr[i-1] + arr[i+ windowSize-1];
       if(sum >maxSum)
       {
        maxSum = sum;
       } 
     }
   }
   return maxSum;
 }

 int main()
 {
   int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
   int len = sizeof(arr)/sizeof(arr[0]);
   int windowSize = 2;
   int maxSum = 0;
   maxSum = maxSumWindowK(arr,len, windowSize);
   printf("Maximum subArray of size %d is :%d\n", windowSize, maxSum);
   return 0;
 }
