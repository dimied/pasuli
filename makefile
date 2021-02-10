
FILES = *.c cylinder/*.c fruits/*.c shells/*.c spiral/*.c sphere/*.c surfaces/*.c torus/*.c

all: clean doall # doopt


doall: #*.c #*.o surfaces/*.o
	gcc -o ex  ${FILES} -lm
	#gcc -o ex *.o surfaces/*.o -lm

doopt:
	gcc -Os -o ex_opt  ${FILES} -lm

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt