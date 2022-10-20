#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double x, func, sum, r, fact = 1, first = 1;
	int n,m;
	printf("Enter the argument value: ");
	scanf("%lf", &x);
	printf("Set the number of summands: ");
	scanf("%d", &n);
	func = sin(x);
	printf("\nThe exact value of the function is equal: %lf", func);

	sum = x;
	r = x;
	for (int i = 1; i < n; i++) {
		r *= -(x * x) / (2 * i * (2 * i + 1));
		sum += r;
	}

	printf("\nThe partial sum of the series is equal: %lf\n", sum);

	printf("\nOutput of the first three terms of the Taylor series: \n");

	r = x;
	for (int i = 1; i <= 3; i++) {
		printf("%E\n", r);
		r *= -(x * x) / (2 * i * (2 * i + 1));
	}
	printf("\n");

	r = x;
	m = 2 * n - 6;
	printf("Output of the last three terms of the Taylor series: \n");
	for (int j = 1; j < 2 * n; j++) {
		fact *= j;
		if (m < j && j % 2 != 0) {
			r = first * (pow(x, j)) / (fact);
			printf("%E\n", r);
			first *= -1;
			m++;
		}
		}
}