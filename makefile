
FILES2 = cylinder/*.c fruits/*.c shells/*.c spiral/*.c sphere/*.c 
FILES3 = surfaces/*.c torus/*.c
FILES_SPLINES = splines/*.c 
FILES_SF = superformula/*.c
FILES_REPO = repository/*.c
FILES_UTIL = util/*.c
EX_FILES = examples/glut_helpers.c examples/pasuli_mesh.c examples/pasuli_mesh_util.c examples/pasuli_mesh_opengl.c

SPHERE_FILES = sphere/*.c
SPHERE_TEST_FILES = sphere/tests/*.c
SPHERE_ALL_FILES = ${SPHERE_FILES} ${SPHERE_TEST_FILES}

ALL_PASULI_FILES = ${SPHERE_ALL_FILES}

MYINT_FILES = myint/*.c
UTIL_INTERPRETER_FILES = util/memory.c util/output.c util/log_stack.c
INTERPRETER_FILES = interpreter/*.c
INTERPRETER_TEST_FILES = interpreter_example_tests.c

PASULI_TESTS = pasuli_test/*.c

OGL_TEST_FILES = ogl_compress/*.c
#
#
#
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

#interpreter_example.c interpreter.c interpreter_text.c interpreter_progs.c prime_compressor.c memory.c myint.c log_stack.c myint_test_data.c myint_test.c 
interpreter: ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES}
	rm -f ./intertest
	gcc -Wall -pedantic -g -Os -B -lc -DIS_PEDANTIC_GCC -o intertest ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES} -lm

interpreter_test: ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES} ${ALL_PASULI_FILES}
	rm -f ./pasulitest
	gcc -Wall -pedantic -g -Os -B -lc -DIS_PEDANTIC_GCC -DENABLE_PASULI_TEST=1 -o pasulitest ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${UTIL_INTERPRETER_FILES} ${ALL_PASULI_FILES} -lm

pasuli_test:  pasulitests.c ${PASULI_TESTS} ${INTERPRETER_FILES} ${UTIL_INTERPRETER_FILES} ${ALL_PASULI_FILES}
	rm -f ./pasulitest
	gcc -Wall -pedantic -g -Os -B -lc -DIS_PEDANTIC_GCC -DENABLE_PASULI_TEST=1 -o pasulitest pasulitests.c ${PASULI_TESTS} ${INTERPRETER_FILES} ${UTIL_INTERPRETER_FILES} ${ALL_PASULI_FILES} -lm

showtestsizes15:
	nm --size-sort pasulitest | grep '[sS]phere'| tail -15

interpreter2: ${INTERPRETER_TEST_FILES}  ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES}
	rm -f ./intertest
	gcc -Wall -g -Os -B -lc -o intertest ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES} -lm

interpreter_use_tcc: ${INTERPRETER_TEST_FILES}  ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES}
	rm -f ./intertest
	tcc -std=c11 -I./ -Wall -vv -fno-common -g -Os -B -ltcc -lm -o intertest ${INTERPRETER_TEST_FILES} ${INTERPRETER_FILES} compressor/prime_compressor.c ${MYINT_FILES} ${UTIL_INTERPRETER_FILES}

showsizes15:
	nm --size-sort intertest | tail -15

showsizes30:
	nm --size-sort intertest | tail -30

showsizes50:
	nm --size-sort intertest | tail -50

showsizes50_extern:
	nm --size-sort -g intertest | tail -50

ogl: ogl_test.c ogl_names.c opengl_header_parser.c file_utils.c ${OGL_TEST_FILES}
	rm -f ogl_test
	gcc -Wall -pedantic -g -Os -lc -ldl -masm=intel -o  ogl_test ogl_test.c ogl_names.c opengl_header_parser.c file_utils.c ${OGL_TEST_FILES}

showogl5:
	nm --size-sort ogl_test | tail -5

showcomp10:
	nm --size-sort ogl_test | grep 'decompress' | tail -10 

clean:
	rm -f *.o 
	rm -f */*.o
	rm -f ./ex
	rm -f ./ex_opt