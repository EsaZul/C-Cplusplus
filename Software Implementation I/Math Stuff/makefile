# target: dependencies
# <tab> rule
#
# make (without arguments) executes first rule
# Ideally, one target for every object file


math_stuff: math_stuff.o
	c99 -lm -o math_stuff math_stuff.o

math_stuff.o: math_stuff.c
	c99 -lm -c math_stuff.c
