all: vala_interpreter lexer_test

vala_interpreter: vala_interpreter.o
	cc -o vala_interpreter vala_interpreter.o

vala_interpreter.o: vala_interpreter.c
	cc -c vala_interpreter.c -o vala_interpreter.o
	
clean:
	rm -rf vala_interpreter
	rm -rf vala_interpreter.o

lexer.yy.c: lexer.l
	flex -o lexer.yy.c lexer.l

lexer.o: lexer.yy.c
	cc -c lexer.yy.c -o lexer.o

lexer_test: lexer_test.o
	cc -o lexer_test lexer_test.o

lexer_test.o: lexer_test.c vala_interpreter_core.h
	cc -c lexer_test.c -o lexer_test.o

