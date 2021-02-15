
FILES1 = pasuli_const.c pasuli_approx.c pasuli_defs.c pasuli_repository.c pasuli_repository_constdata.c pasuli_desc_parser.c
FILES2 = cylinder/*.c fruits/*.c shells/*.c spiral/*.c sphere/*.c 
FILES3 = superformula/*.c surfaces/*.c torus/*.c sf3d_examples.c

all: clean doall # doopt


doall:
	gcc -o ex ex.c ${FILES1} ${FILES2} ${FILES3} -lm
	#gcc -o ex *.o surfaces/*.o -lm

do99:
	gcc -std=c99 -o ex ex.c ${FILES1} ${FILES2} ${FILES3} -lm

doopt:
	gcc -Os -o ex_opt  ${FILES} -lm

filegen:
	gcc -Os -o gen_files temp_gen.c

genhtml:
	gcc -Os -o gen_html gen_html.c ${FILES1} ${FILES2} ${FILES3} -lm

# For Ubuntu: You need to install freeglut3 package
opengl:
	gcc -o ex_ogl  opengl_sample.c ${FILES1} ${FILES2} ${FILES3} -lm -lGL -lGLU -lglut

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt