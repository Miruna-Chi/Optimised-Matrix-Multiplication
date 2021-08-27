# Optimised-Matrix-Multiplication
A tweaked Matrix Multiplication algorithm to take into account Computer Architecture for a substantial 7x speedup (+ a detailed comparison to other algorithms))

### 1. Solution Description
  #### 1.1) neopt
    - Multiplication + Triangular Matrix Optimisation
    - Execution Time
  #### 1.2) opt_m
    - Approaches used to optimise the multiplication
    - Speed-up
    - Execution Time
    - CACHE Explanation
  #### 1.3) opt_blas
    - Used functions
    - Speed-up
    - Execution Time
### 2. Comparison + Analysis
    - Charts
    - Performance conclusions

### 3. Resources




### 1. Solution Description
#### 1.3) opt_blas
    Used the following functions:
    
#####   cblas_dgemm (d - double, mm – matrix-matrix)
      - calculates: C := alpha*op(A)*op(B) + beta*C
      
      Parameters:
        alpha, beta = scalars
        A, B, C – matrice
        op(X) = X sau op(X) = X transpus
   
      
 ##### cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, B, N, B, N, 0.0, C, N);
      - calculates B * Bt
      
      Parameters:
        1. CblasRowMajor – matrices are stored row by row, as a vector
        2. CblasNoTrans – first matrix is not transposed
        3. CblasTrans – second matrix is transposed
        4, 5, 6, 9, 11, 14 – matrices' dimensions: N * N, so all of them will be N
        7. alpha = 1.0
        8. first matrix: B
        10. second matrix: B
        12. beta: 0.0 (does not add matrix C)
        13. C is where the result will be stored
      
      
 ##### cblas_dtrmm (d – double, tr -triangular, mm – matrix-matrix)
      - calculates B := alpha*op(A)*B or B := alpha*B*op(A)
      
      Parameters:
        1. alpha = scalar
        2. A, B – matrix
        3. op(X) = X or op(X) = X transpus
      
      Calculates: A * C (C = B * Bt now)
      
  ##### cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, C, N);
      Parameters:
        1. CblasRowMajor – matrices are stored row by row, as a vector
        2. CblasLeft – operation type
        3. CblasUpper – A is upper triangular
        4. CblasNoTrans – A is not transposed
        5. CblasNonUnit – A is not unit triangular (elem != 0 doar pe diagonala)
        6, 7, 10, 12 – matrices' dimensions: N
        8. alpha = 1.0
        9. first natrix: A
        11. second matrix and result holder: C
        
        We use cblas_dtrmm a second time to calculate At * A, the result will be stored in A.
        
  Now we are left with A + C. We can't use cblas_dgemm because we would need a third matrix
  as a param. Idea: cblas_daxpy, used to add two vectors. Since our matrices are stored in vectors,
  line by line, nothing could be simpler.

  ##### cblas_daxpy(N * N, 1.0, A, 1, C, 1)
      y := a*x + y
      a is a scalar,
      x is a sparse vector stored in compressed form,
      y is a vector in full storage form.

      Parameters:
      1. size of arrays
      2. a
      3. the vector x
      4. increment step for x
      5. the vector y
      6. increment step for y
   
   ##### Execution Time: :O
        N=400     Time=0.044
        N=800     Time=0.226
        N=1200    Time=0.641


#### 1.1) neopt
    Formula: C = A × B × Bt + At × A
    
    As can be seen from the comments, we calculated each multiplication
    separately by intuitive methods, without any optimization, except:
    - the fact that matrix B was overwritten to save an intermediate result, instead of
    allocating another matrix
    - Switched indices to get a transposed matrix, instead of performing an
    actual transposition
    
    So:
    1. Calculate B x Bt, the result will be in the matrix C
    2. Copy C to B (we no longer need B), but we need the previously calculated result
    and, simultaneously, that C be zeroed for the next multiplication
    3. Calculate A x res_step_1 (located in B). The result will be in matrix C
    4. Calculate the final result: C += At x A
    How do we keep in mind that A is an upper triangular matrix?
      1. When we calculate A x inter_res and we have **A[i][k]**: k >= i
      2. When calculating At x A things get a little complicated. At will be lower triangular, A
    will be upper triangular:
        For At[k][i] = A[i][k]: k <= i
        For A[k][j]: j >= k
   ##### Execution times (execrable):
        N=400     Time=1.042
        N=800     Time=8.162
        N=1200    Time=26.965
        
        
  #### 1.2) opt_m 
  
  ##### Optimisation No. 1: Loop reorder
        In the neopt version, we opted for i-j-k intuitive ordering for all loops.
        Now we have to start comparing and figure out the right order.
        
        How are we gonna do that?
        - We take the innermost loop and think about the order in which the matrices are processed:
          * constant - neither of the indices change in this loop -> perfect
          * sequential - the matrix is processed row by row -> good
          * non-sequential - column by column (skips entire lines) -> not good
          
        How did we figure out what's good and what's bad?
        - In memory, those matrices are stored row by row. Let's think about CACHE memory for a bit. It's our fastest available memory, let's use it wisely.
        If an element is accessed, our CACHE will store that element and the following X elements into a line in memory (depending on how long our CACHE lines are).
        
        Accessing the next element on the row means getting a HIT in CACHE, which is great (we reached our data the fastest way).
        
        Accessing an element on the next row every time means loading every row, one by one in CACHE and never using that row -> MISS rate 100% -> Basically, we render
        cache memory useless.
  
   

