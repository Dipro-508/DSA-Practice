#include <stdio.h>

long long sum_ap_formula(long long a1, long long d, long long n) {
    return n * (2 * a1 + (n - 1) * d) / 2;
}

int main(void) {
    long long a1, d, n;
    printf("Enter first term a1, common difference d, number of terms n: ");
    if (scanf("%lld %lld %lld", &a1, &d, &n) != 3) return 1;
    if (n <= 0) { printf("n must be positive\n"); return 1; }
    long long sum = sum_ap_formula(a1, d, n);
    printf("Sum of AP = %lld\n", sum);
    return 0;
}
