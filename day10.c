//Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right;

    printf("Enter a string: ");
    scanf("%s", str);  

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            printf("Not a palindrome\n");
            return 0;
        }
        left++;
        right--;
    }

    printf("Palindrome\n");
    return 0;
}
