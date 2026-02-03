// Count and display the number of comparisons performed.

#include <stdio.h>

int main()
{
    int n, i, k;
    int count = 0;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        count++;                // comparison made
        if(arr[i] == k)
        {
            printf("Key found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Key not found\n");
    }

    printf("Number of comparisons: %d\n", count);

    return 0;
}



