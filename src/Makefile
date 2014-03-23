all: vala_interpreter

vala_interpreter: vala_interpreter.o
	cc -o vala_interpreter vala_interpreter.o

vala_interpreter.o: vala_interpreter.c
	cc -c vala_interpreter.c -o vala_interpreter.o
	
clean:
	rm -rf vala_interpreter
	rm -rf vala_interpreter.o
