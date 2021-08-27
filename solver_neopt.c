/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */

double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	int i, j, k;

	double *C = malloc(N * N * sizeof(double));

	if (NULL == C) {
		perror("malloc in neopt");
		exit(EXIT_FAILURE);
	}

	// inter_res = B * Bt, saved in C
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i * N + j] = 0;
			for (k = 0; k < N; k++) {
				C[i * N + j] += B[i * N + k] * B[j * N + k];
			}
		}
	}

	// copy C to B
	double *p = &C[0];
	double *q = &B[0];
	for (i = 0; i < N * N; i++) {
		*(q++) = *p;
		*(p++) = 0;
	}

	// C = A * inter_res
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = i; k < N; k++) {
				C[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}

	// C += At * A
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k <= j && k <= i; k++) {
				C[i * N + j] += A[k * N + i] * A[k * N + j];
			}
		}
	}

	return C;
}
