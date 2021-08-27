/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */

double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
	int i, j, k, bi, bj, bk;
	register int blockSize = 40;

	double *C = calloc(N * N, sizeof(double));

	if (NULL == C) {
		perror("malloc in neopt");
		exit(EXIT_FAILURE);
	}

	// inter_res = B * Bt
	for(bi = 0; bi < N; bi += blockSize)
        for(bj = 0; bj < N; bj += blockSize)
            for(bk = 0; bk < N; bk += blockSize) {
				register double *B_i_k = &B[bi * N + bk];
				register double *B_trans_j_k = &B[bj * N + bk];
				register double	*inter_res_i_j = &C[bi * N + bj];

				for (i = 0; i < blockSize; i++) {
					
					
					for (j = 0; j < blockSize; j++) {
						
						register double sum = *inter_res_i_j;

						for (k = 0; k < blockSize; k += 40) {
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);
							sum +=  *(B_i_k++) * *(B_trans_j_k++);

						}
						*(inter_res_i_j++) = sum;
						B_i_k -= blockSize;
						B_trans_j_k += N - blockSize;
					}
					B_i_k += N;
					B_trans_j_k -= blockSize * N;
					inter_res_i_j += N - blockSize;
				}
			}

	register double *p = &C[0];
	register double *q = &B[0];
	for (i = 0; i < N * N; i += 40) {
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
		*(q++) = *p;
		*(p++) = 0;
	}

	// C = A * inter_res
	for(bi = 0; bi < N; bi += blockSize)
		for(bk = bi; bk < N; bk += blockSize) {
			register int k_on_diag = bi == bk ? 1 : 0;
			
			for(bj = 0; bj < N; bj += blockSize) {
				
				register double *C_i_j = &C[bi * N + bj];

				for (i = 0; i < blockSize; i++) {
					
					
					if (k_on_diag)
						k = i;
					else k = 0;

					register double *A_i_k = &A[(bi + i) * N + bk + k];
					register double *inter_res_k_j = &B[(bk + k) * N + bj];
					for( ; k < blockSize; k++) {
						
						
						for (j = 0; j < blockSize; j += 40) {
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);	
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);
							(*C_i_j++) += *A_i_k * *(inter_res_k_j++);

						}
						A_i_k++;
						C_i_j -= blockSize;	
						inter_res_k_j += N - blockSize;
					}

					C_i_j += N;
				}
			}
		}

	// C += At * A
	for(bk = 0; bk < N; bk += blockSize) {
		register double *A_k_i = &A[bk * N + bk];
		register double *A_k_j = &A[bk * N + bk];
		register double *C_i_j = &C[bk * N + bk];
		for(bi = bk; bi < N; bi += blockSize) {
			for(bj = bk; bj < N; bj += blockSize) {
				for (k = 0; k < blockSize; k++) {
					for (i = 0; i < blockSize; i++) {
						for (j = 0; j < blockSize; j += 40) {
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);
							*(C_i_j++) += *A_k_i * *(A_k_j++);

						}
						A_k_i++;
						A_k_j -= blockSize;
						C_i_j += N - blockSize;
					}

					A_k_i += N - blockSize;
					A_k_j += N;
					C_i_j -= blockSize * N;
				}
				A_k_i -= blockSize * N;
				A_k_j += -blockSize * N + blockSize;
				C_i_j += blockSize;

			}
			A_k_j += - N + bk;
			A_k_i += blockSize;
			C_i_j += - N + bk + blockSize * N;
		}
	}
	
	return C;
}
