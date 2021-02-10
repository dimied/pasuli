
FILES1 = *.c cylinder/*.c fruits/*.c 
FILES2 = shells/*.c spiral/*.c sphere/*.c 
FILES3 = superformula/*.c surfaces/*.c torus/*.c

all: clean doall # doopt


doall: #*.c #*.o surfaces/*.o
	gcc -o ex  ${FILES1} ${FILES2} ${FILES3} -lm
	#gcc -o ex *.o surfaces/*.o -lm

doopt:
	gcc -Os -o ex_opt  ${FILES} -lm

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt