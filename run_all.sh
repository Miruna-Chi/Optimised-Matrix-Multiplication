#!/bin/bash
module load compilers/gnu-5.4.0
make
./solver_blas input
./solver_opt_m input
./solver_neopt input
make clean