//  Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n)
{
    int prefixSum = 0;
    int count = 0;

    int freq[20001] = {0};

    freq[10000] = 1;

    for(int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if(freq[prefixSum + 10000] > 0)
            count += freq[prefixSum + 10000];

        freq[prefixSum + 10000]++;
    }

    return count;
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of subarrays with sum 0 = %d", result);

    return 0;
}