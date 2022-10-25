#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double x, function, sum, lastTerm, temp, factorial = 1, last3, changingSign, error;
	int i = 1, j, termCount = 0;

	printf("Enter the argument value: ");
	scanf("%lf", &x);

	//Calculating the sum of the Taylor series for the function sin(x)
	function = sin(x);
	printf("\nThe exact value of the function is equal: %E\n", function);

	//Calculating the sum of the Taylor series for the function sin(x)
	lastTerm = x;
	sum = x;
	do
	{
		lastTerm *= -(x * x) / (2 * i * (2 * i + 1));
		sum += lastTerm;
		termCount++;
		i++;
	} while (fabs(lastTerm) >= 1e-10);

	//The difference between the answer from math.h and the resulting sum of the Taylor series
	error = abs(function - sum);

	printf("The resulting sum of the series: %E\n", sum);
	printf("%d terms of the Taylor series summed\n", termCount);
	printf("\nThe difference between the answer from math.h and the resulting sum of the Taylor series: %E\n", error);

	printf("\nOutput of the first three terms of the Taylor series: \n");
	temp = x;
	for (i = 1; i <= 3; i++) {
		printf("%E\n", temp);
		temp *= -(x * x) / (2 * i * (2 * i + 1));
	}
	printf("\n");

	temp = x;

	/*Let's take the number of terms and subtract from them the last 3 terms that we need to display. 
	But since even powers and factorials of even numbers are skipped in the series, you will have 
	to multiply the number obtained earlier by 2.*/
	last3 = 2 * (termCount - 3);

	printf("Output of the last three terms of the Taylor series: \n");

	/*If the number of terms is even, then the antepenultimateand last terms will be positive,
	and the penultimate term will be negative.
	If the number of terms is odd, then the antepenultimate and last terms will be negative, 
	and the penultimate term will be positive.*/
	changingSign = termCount % 2 != 0 ? 1 : -1;

	//Output the last three terms of the Taylor series
	for (j = 1; j < 2 * termCount; j++) {
		factorial *= j;

		/*In this condition, we cut off all members of the series, except for the last three, 
		and even numbers, since in our expansion of the Taylor series there are no even numbers 
		in powers and factorials of numbers.*/
		if (last3 < j && j % 2 != 0) {
			temp = changingSign * (pow(x, j)) / (factorial);
			printf("%E\n", temp);
			changingSign *= -1;
			last3++;
		}
	}
}