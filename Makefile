CC=gcc
CFLAGS=-Wall -Werror -O0 -g -lm
LIBDIRS=-L/usr/lib64/atlas
LIBS=-lsatlas

all: compare solver_blas solver_neopt solver_opt_m

solver_blas: solver_blas.c main.c utils.h
	$(CC) $(CFLAGS) $^ $(LIBDIRS) $(LIBS) -o $@

solver_neopt: solver_neopt.c main.c utils.h
	$(CC) $(CFLAGS) $^ -o $@

solver_opt_m: solver_opt.c main.c utils.h
	$(CC) $(CFLAGS) $^ -o $@

compare: compare.c utils.h
	$(CC) $(OPT_CFLAGS) $^ -lm -o $@

clean:
	rm -rf compare solver_blas solver_neopt solver_opt_m out*
