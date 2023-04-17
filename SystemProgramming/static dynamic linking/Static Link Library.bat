 gcc –c mysum.c
ar rcs libmylib.a mysum.o
gcc -static t.c -L. –lmylib
 a.out
