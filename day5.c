// A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>


void mergeLogs(int* log1, int size1, int* log2, int size2, int* mergedLog) {
    int i = 0, j = 0, k = 0;

   
    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            mergedLog[k++] = log1[i++];
        } else {
            mergedLog[k++] = log2[j++];
        }
    }

    while (i < size1) {
        mergedLog[k++] = log1[i++];
    }

    
    while (j < size2) {
        mergedLog[k++] = log2[j++];
    }
}


int main() {
    int server1Log[] = {1, 3, 5, 7};  
    int server2Log[] = {2, 4, 6, 8, 10};
    
    int size1 = sizeof(server1Log) / sizeof(server1Log[0]);
    int size2 = sizeof(server2Log) / sizeof(server2Log[0]);
    int mergedLog[size1 + size2];

    mergeLogs(server1Log, size1, server2Log, size2, mergedLog);

    printf("Merged Chronological Log: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedLog[i]);
    }

    return 0;
}
