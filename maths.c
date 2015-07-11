#include "maths.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double pythagorasTheorem(double sideA, double sideB)
{
	double aSquared = sideA * sideA;
	double bSqaured = sideB * sideB;
	double answer = sqrt(aSquared + bSqaured);
	return answer;
}

void pythagorasTheoremInput ()
{
	char input[256];

	double sides[2];
	int count = 0;
	do {
		printf("Enter side %d:\n", count);
		fgets(input, sizeof(input), stdin);
		sides[count] = atof(input);
		count++;
	} while (
		count < (sizeof(sides) / sizeof(double))
	);
	double ans = pythagorasTheorem(sides[0], sides[1]);
	printf("Answer: %f\n", ans);
}

double nthTerm (double *terms) 
{
	double difference = terms[1] - terms[0];
	double extra = difference - terms[0];
	printf("%f n  + %f\n", difference, -extra);
}

void nthTermInput ()
{
	char input[256];
	printf("Enter terms seperated by commas:\n");
	fgets(input, sizeof(input), stdin);

	// Get length of input array
	int length = strlen(input);
	int i = 0;
	int count = 0;

	for (i = 0; i < length; i++) {
		if (input[i] == ",") {
			count++;
		}
	}
	count++;

	double myTerms[count];

	char *token = strtok(input, ",");
	i = 0;
	while (token) {
		myTerms[i] = atof(token);
		i++;
		token = strtok(NULL, ",");
		printf("%d\n", i);
	}
	nthTerm(myTerms);
}

void shareRatio(char ratio[], double amount, double *ans)
{
	// Count number of colons
	int length = strlen(ratio);
	int i = 0;
	int count = 0;

	char colon = ':';

	for (i = 0; i < length; i++) {
		if (ratio[i] == colon) {
			count++;
		}
	}

	count++;
	double nums[count];
	int lengthNums = count;
	count++;
	char *token = strtok(ratio, ":");
	i = 0;
	while (token) {
		nums[i] = atof(token);
		i++;
		token = strtok(NULL, ":");
	}

	double total = 0;

	for (i = 0; i < lengthNums; i++) {
		total = total + nums[i];
	}

	double perUnit = amount / total;

	for (i = 0; i < lengthNums; i++) {
		ans[i + 1] = nums[i] * perUnit;
	}
	
}

void shareRatioInput()
{
	char amount[256];
	char ratio[256];
	printf("Enter ratio:\n");
	fgets(ratio, sizeof(ratio), stdin);
	printf("Enter amount to share:\n");
	fgets(amount, sizeof(amount), stdin);

	int length = strlen(ratio);
	int i = 0;
	int count = 0;

	char colon = ':';

	for (i = 0; i < length; i++) {
		if (ratio[i] == colon) {
			count++;
		}
	}
	count++;
	double ans[count];
	ans[0] = count + 1;
	shareRatio(ratio, atof(amount), ans);	
	i = 1;
	for (i = 1; i < ans[0]; i++) {
		if (i > 1) {
			printf(":");
		}
		printf("%f", ans[i]);
	}
	printf("\n");

}