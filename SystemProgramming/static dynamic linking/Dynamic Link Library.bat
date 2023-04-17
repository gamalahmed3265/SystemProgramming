 gcc –c -fPIC mysum.c
 gcc –shared -o libmylib.so mysum.o
 gcc t.c -L. –lmylib
export LD_LIBRARY_PATH=./
 a.out