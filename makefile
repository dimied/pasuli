
FILES1 = pasuli_const.c pasuli_approx.c pasuli_defs.c pasuli_repository.c pasuli_repository_constdata.c
FILES2 = cylinder/*.c fruits/*.c shells/*.c spiral/*.c sphere/*.c 
FILES3 = superformula/*.c surfaces/*.c torus/*.c sf3d_examples.c

all: clean doall # doopt


doall: #*.c #*.o surfaces/*.o
	gcc -o ex ex.c ${FILES1} ${FILES2} ${FILES3} -lm
	#gcc -o ex *.o surfaces/*.o -lm

doopt:
	gcc -Os -o ex_opt  ${FILES} -lm

# For Ubuntu: You need to install freeglut3 package
opengl:
	gcc -o ex_ogl  opengl_sample.c ${FILES1} ${FILES2} ${FILES3} -lm -lGL -lGLU -lglut

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt