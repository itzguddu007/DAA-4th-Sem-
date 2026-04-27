#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float score;
} Student;

void merge(Student arr[], int l, int m, int r, int order) {
    int i = l, j = m + 1, k = 0;
    Student temp[r - l + 1];

    while (i <= m && j <= r) {
        if ((order == 1 && arr[i].score < arr[j].score) ||
            (order == 2 && arr[i].score > arr[j].score)) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(Student arr[], int l, int r, int order) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, order);
        mergeSort(arr, m + 1, r, order);
        merge(arr, l, m, r, order);
    }
}

int main() {
    int n, order;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student arr[n];

    printf("Enter student name and score:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %f", arr[i].name, &arr[i].score);
    }

    printf("\nChoose order:\n1. Ascending\n2. Descending\n");
    scanf("%d", &order);

    mergeSort(arr, 0, n - 1, order);

    printf("\nSorted Student List:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %.2f\n", arr[i].name, arr[i].score);
    }

    return 0;
}