#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char **arr, int l, int m, int r) {
    int i = l, j = m + 1, k = 0;

    char *temp[r - l + 1];

    while (i <= m && j <= r) {
        if (strcmp(arr[i], arr[j]) < 0)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(char *arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);
    char *words[n];   // no MAX
    printf("Enter words:\n");

    for (int i = 0; i < n; i++) {
        char temp[100];   // small buffer just for input
        scanf("%s", temp);
        words[i] = malloc(strlen(temp) + 1);
        strcpy(words[i], temp);
    }

    mergeSort(words, 0, n - 1);

    printf("\nSorted words:\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}