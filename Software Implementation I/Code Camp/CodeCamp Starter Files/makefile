# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

CodeCamp: CodeCamp.o CodeCampTester.o
	c99 -o CodeCamp CodeCamp.o CodeCampTester.o

CodeCamp.o: CodeCamp.c
	c99 -c CodeCamp.c

CodeCampTester.o: CodeCampTester.c
	c99 -c CodeCampTester.c
