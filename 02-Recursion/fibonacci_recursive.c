#include <stdio.h>

long long fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n;
    printf("Enter n (compute nth Fibonacci number): ");
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) { printf("n must be non-negative\n"); return 1; }
    printf("Fib(%d) = %lld\n", n, fib(n));
    return 0;
}
