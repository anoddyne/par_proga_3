#include <stdio.h>
#include <math.h>

double funcSin(double x) {
	double absLastTerm, lastTerm = x, sum = x;
	absLastTerm = fabs(lastTerm);

	// Calculating the sum of a series at the point
	for (int i = 1; absLastTerm >= 1e-10; i++)
	{
		lastTerm *= -(x * x) / (2 * i * (2 * i + 1));
		sum += lastTerm;
		absLastTerm = fabs(lastTerm);
	}

	return sum;
}

int main() {
	double a = -10, b = 10, funcMathSin;
	int n = 20, count = 0;

	// Calculation of the counting step
	double h = (b - a) / n;

	for (double x = a; x <= b; x += h) {

		// Calculation and output of function values in the first and last three arguments
		if (count <= 2 || count >= n - 2 && count <= n) {
			funcMathSin = sin(x);
			printf("The value of the sine function at the point %.2lf = %E\n", x, funcMathSin);
			printf("The value of the Taylor series at the point %.2lf = %E\n", x, funcSin(x));
			printf("The difference between values: %E\n\n", fabs(funcMathSin - funcSin(x)));
		}

		count++;
	}
}