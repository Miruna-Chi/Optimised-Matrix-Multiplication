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
#### 1.1) neopt
    Formula: C = A × B × Bt + At × A
    
    As can be seen from the comments, we calculated each multiplication
    separately by intuitive methods, without any optimization, except:
    - the fact that matrix B was overwritten to save an intermediate result, instead of
    allocating another matrix
    - Switched indices to get a transposed matrix, instead of performing an
    actual transposition
    
    So:
    1. Calculate **B x Bt**, the result will be in the matrix C
    2. Copy C to B (we no longer need B), but we need the previously calculated result
    and, simultaneously, that C be zeroed for the next multiplication
    3. Calculate A x res_step_1 (located in B). The result will be in matrix C
    4. Calculate the final result: **C += At x A**
    How do we keep in mind that A is an upper triangular matrix?
      1. When we calculate **A x inter_res** and we have **A[i][k]**: **k >= i**
      2. When calculating **At x A** things get a little complicated. At will be lower triangular, A
    will be upper triangular:
        For **At[k][i]** = **A[i][k]**: **k <= i**
        For **A[k][j]**: **j >= k**
   ##### Execution times (execrable):
        N=400     Time=1.042
        N=800     Time=8.162
        N=1200    Time=26.965
   

