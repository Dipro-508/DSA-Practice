#include <stdio.h>
int main()
{int arr[100], n, i, sum = 0;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d elements:\n", n);
for(i = 0; i < n; i++){scanf("%d", &arr[i]);}
printf("\nArray Elements:\n");
for(i = 0; i < n; i++){printf("%d ", arr[i]);}
for(i = 0; i < n; i++){sum += arr[i];}
printf("\n\nSum = %d\n", sum);
return 0;}