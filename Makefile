# kol: hellomake.c hellofunc.c libfftw3.a
# 	gcc -o kol hellomake.c hellofunc.c libfftw3.a

# DFFT: dfft.c  libfftw3.a
# 	gcc -o DFFT dfft.c  libfftw3.a -lm

# main: main.c  libfftw3.a
# 	gcc -o main main.c  libfftw3.a -lm

comp: comp.c  libfftw3.a
	gcc -o comp comp.c  libfftw3.a -lm