

all: clean doall


doall: *.c *.o surfaces/*.o
	gcc -o ex *.c surfaces/*.c -lm
	#gcc -o ex *.o surfaces/*.o -lm

clean:
	rm -f *.o 
	rm -f */*.o