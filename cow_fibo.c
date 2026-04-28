#include <stdio.h>

int main() {
    int n;

    printf("Enter number of years (n): ");
    scanf("%d", &n);

    // Validate input
    if (n < 0) {
        printf("Invalid input! Years cannot be negative.\n");
        return 0;
    }

    // Base cases
    if (n == 0 || n == 1) {
        printf("Total cows = 1\n");
        return 0;
    }
    if (n == 2) {
        printf("Total cows = 2\n");
        return 0;
    }

    int a = 1, b = 1, c = 2, d;

    for (int i = 3; i <= n; i++) {
        d = c + a;  // F(n) = F(n-1) + F(n-3)

        // Shift values
        a = b;
        b = c;
        c = d;
    }

    printf("Total cows after %d years = %d\n", n, c);

    return 0;
}