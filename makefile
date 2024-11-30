
FILES2 = cylinder/*.c fruits/*.c shells/*.c spiral/*.c sphere/*.c 
FILES3 = surfaces/*.c torus/*.c
FILES_SPLINES = splines/*.c 
FILES_SF = superformula/*.c
FILES_REPO = repository/*.c
FILES_UTIL = util/*.c
EX_FILES = examples/glut_helpers.c examples/pasuli_mesh.c examples/pasuli_mesh_util.c examples/pasuli_mesh_opengl.c

all: clean doall # doopt

.PHONY: doall trigtest

doall:
	gcc -Wall -o ex ex.c ${FILES_UTIL} ${FILES2} ${FILES3} \
	${FILES_SF} ${FILES_REPO} ${FILES_SPLINES} -lm
	#gcc -o ex *.o surfaces/*.o -lm

do99:
	gcc -std=c99 -o ex ex.c ${FILES1} ${FILES2} ${FILES3} -lm

doopt:
	gcc -Os -o ex_opt  ${FILES} -lm

filegen:
	gcc -Os -o gen_files temp_gen.c

trigtest:
	rm -f trigtest
	gcc -Os -o trigtest trigtest.c -lm

genhtml:
	gcc -Os -o gen_html gen_html.c ${FILES_UTIL} ${FILES2} ${FILES3} -lm

# For Ubuntu: You need to install freeglut3 package
opengl:
	gcc -Wall -pedantic -Os -o ex_ogl  examples/opengl_sample.c  ${EX_FILES} ${FILES_UTIL} ${FILES2} ${FILES3} -lm -lGL -lGLU -lglut
	strip --strip-all ex_ogl

interpreter: interpreter_example.c interpreter.c
	rm -f ./intertest
	gcc -Wall -Os -B -lm -o ./intertest interpreter_example.c interpreter.c

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt