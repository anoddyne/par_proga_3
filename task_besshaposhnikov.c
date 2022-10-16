#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	double x, func, sum, r, e, sum_1;
	double last = 0;
	int n;
	printf("Enter the argument value: ");
	scanf("%lf", &x);
	printf("Set the number of summands: ");
	scanf("%d", &n);
	func = sin(x);
	printf("The exact value of the function is equal: %lf\n", func);
	sum = x;
	r = x;
	for (int i = 1; i < n; i++) {
		r *= -(x * x) / (2 * i * (2 * i + 1));
		sum += r;
		last = r;		
	}
	r = x;
	for (int i = 1; i <= 3; i++) {
		printf("%lf\n", r);
		r *= -(x * x) / (2 * i * (2 * i + 1));
	}
	for (int i = n-2; i <= n ; i++) {
		printf("%lf\n", r);
		r *= -(x * x) / (2 * i * (2 * i + 1));
	}
	printf("\nThe partial sum of the series is equal: %lf", sum);
}