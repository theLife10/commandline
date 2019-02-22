#
# EE 4374 Assignment 2 Makefile
# Author: Jesus Garcia
#
command: jgarcia_argtok.o jgarcia_exec.o jgarcia_prog2.o 
	gcc jgarcia_argtok.o jgarcia_exec.o jgarcia_prog2.o -o command

jgarcia_argtok.o: jgarcia_argtok.c
	gcc -c jgarcia_argtok.c jgarcia_argtok.h

jgarcia_exec.o: jgarcia_exec.c
	gcc -c jgarcia_exec.c jgarcia_exec.h

jgarcia_prog2.o: jgarcia_prog2.c
	gcc -c jgarcia_prog2.c

clean:
	rm *.o; rm jgarcia_prog2

demo: command
	./command
