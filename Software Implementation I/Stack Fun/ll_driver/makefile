# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

FloodFill: stack_ll.o ll_driver.o
	c99 -o FloodFill stack_ll.o ll_driver.o

stack_ll.o: stack_ll.c
	c99 -c stack_ll.c

driver.o: ll_driver.c
	c99 -c driver.c