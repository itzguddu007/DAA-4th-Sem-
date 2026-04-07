#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(char **arr, int n, char *key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        int cmp = strcmp(arr[mid], key);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    char key[50];

    printf("Enter number of words: ");
    scanf("%d", &n);

    // allocate array of pointers
    char **arr = (char **)malloc(n * sizeof(char *));

    // allocate memory for each string
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)calloc(50, sizeof(char));
    }

    printf("Enter %d words (in sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter word to search: ");
    scanf("%s", key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Word found at index %d\n", result);
    else
        printf("Word not found\n");

    // free memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}