#include <stdio.h>

int main() {
    int i, j, n, m;

    printf("Enter number of hashtags: ");
    scanf("%d", &n);

    printf("Enter number of regions: ");
    scanf("%d", &m);

    // Declare arrays
    float A[n][m], W[m], result[n];
    char hashtags[n][20];
    char regions[m][20];

    // Input hashtag names
    printf("\nEnter hashtag names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", hashtags[i]);
    }

    // Input region names
    printf("\nEnter region (country) names:\n");
    for(j = 0; j < m; j++) {
        scanf("%s", regions[j]);
    }

    // Input engagement matrix
    printf("\nEnter Hashtag Engagement Matrix:\n");
    for(i = 0; i < n; i++) {
        printf("For %s:\n", hashtags[i]);
        for(j = 0; j < m; j++) {
            printf("  %s: ", regions[j]);
            scanf("%f", &A[i][j]);
        }
    }

    // Input weights
    printf("\nEnter weights for each region:\n");
    for(j = 0; j < m; j++) {
        printf("%s weight: ", regions[j]);
        scanf("%f", &W[j]);
    }

    // Matrix multiplication
    for(i = 0; i < n; i++) {
        result[i] = 0;
        for(j = 0; j < m; j++) {
            result[i] += A[i][j] * W[j];
        }
    }

    // Output
    printf("\nWeighted Hashtag Popularity:\n");
    for(i = 0; i < n; i++) {
        printf("%s = %.2f\n", hashtags[i], result[i]);
    }

    return 0;
}