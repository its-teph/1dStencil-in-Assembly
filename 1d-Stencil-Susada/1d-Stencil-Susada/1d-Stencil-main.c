//Name: Stephanie Joy R. Susada
//Section: S11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


extern void asm_stencil_function(long long int* X, long long int* Y, int size);
extern void simd_1dstencil(long long int* X, long long int* Y, int size);

//C kernel
void stencilOperation(int n, long long int* X, long long int* Y) {
	int i;
	for (i = 3; i < n - 3; i++) {
		Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
	}
}


int main() {
	//caller

	int input, ARRAY_SIZE = pow(2,20);
	long long int* X, *Y, *C_ans;
	int i, counter = 0, count = 0;
	clock_t start, end;
	double time_taken[30];
	float sum = 0;

	//scanf_s("Enter number of elements: %d", &ARRAY_SIZE);

	X = (long long int*)malloc(ARRAY_SIZE * sizeof(long long int));
	Y = (long long int*)malloc(ARRAY_SIZE * sizeof(long long int));
	C_ans = (long long int*)malloc(ARRAY_SIZE * sizeof(long long int));

	srand(time(0));

	// Generate a random integer between 1 and 50
	
	srand(time(0));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		X[i] = (rand() % 50) + 1;
	}
	/*
	for (i = 0; i < ARRAY_SIZE; i++) {
		X[i] = i+1;
		//printf("Random number: %lld\n", X[i]);
	}*/

	printf("\nPlease choose...\n");
	printf("1 - C Language 1d Stencil Function\n");
	printf("2 - x86 Assembly Language\n");
	printf("3 - x86 SIMD using YMM register\n");

	scanf_s("%d", &input);
	//C Function
	if (input == 1) {

		for (i = 0; i < 30; i++) {
			start = clock();
			stencilOperation(ARRAY_SIZE, X, Y);
			end = clock();

			time_taken[i]= ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			sum += time_taken[i];
			//printf("%d - %d = %d\n",start, end, end-start);
		}
		printf("\nC LANGUAGE\n");
		printf("\nStencil Operation Result:\n");
		for (i = 3; i < ARRAY_SIZE - 3 && counter < 5; i++) {
			printf("%lld ", Y[i]);
			counter++;
		}
		printf("\n");
		printf("Average Execution Time: %.2lf us\n", sum / 30);
	}
	//Non SIMD Assembly
	else if (input == 2) {

		for (i = 0; i < ARRAY_SIZE; i++) {
			Y[i] = 0;
		}

		for (i = 0; i < 30;i++) {
			start = clock();
			asm_stencil_function(X, Y, ARRAY_SIZE - 3);
			end = clock();
			time_taken[i] = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			sum += time_taken[i];
		}
		printf("\nNon SIMD x86-64 ASSEMBLY\n");
		printf("\nStencil Operation Result:\n");
		for (i = 0; i < ARRAY_SIZE - 3 && counter < 5; i++) {
			printf("%lld ", Y[i]);
			counter++;
		}
		printf("\n");
		printf("Average Execution Time: %.2f us\n", sum / 30);
	}
	//SIMD Assembly
	else if (input == 3) {

		for (i = 0; i < ARRAY_SIZE; i++) {
			Y[i] = 0;
			//printf("%lld ", Y[i]);
		}
		
		for (i = 0; i < 30;i++) {
			start = clock();
			simd_1dstencil(X, Y, ARRAY_SIZE - 3);
			end = clock();
			time_taken[i] = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			sum = time_taken[i];
		}
		printf("\nSIMD x86-64 ASSEMBLY\n");
		printf("\nStencil Operation Result:\n");
		for (i = 0; i < ARRAY_SIZE - 3 && counter < 5; i++) {
			printf("%lld ", Y[i]);
			counter++;
		}
		printf("\n");
		printf("Average Execution Time: %.2f us\n", sum/30);
	}

	//for checking
	stencilOperation(ARRAY_SIZE, X, C_ans);

	if (input == 2 || input == 3) {
		int s = 0;
		for (i = 3; i < ARRAY_SIZE - 3; i++) {
			//printf("%d - %d \n", C_ans[i], Y[i-3]);
			if (C_ans[i] != Y[i - 3]) {
				count++;
			}
		}
	}

	if (count > 0) {
		printf("\nThere is %d error", count);
	}
	else (printf("\n0 error. Output is correct\n\n"));

	free(X);
	free(Y);
	
	return 0;
}
