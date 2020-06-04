# target: dependencies
# <tab> rule
#
# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final
#
flood_fill: flood_fill.o
	c99 -o flood_fill flood_fill.o

flood_fill.o: flood_fill.c
	c99 -c flood_fill.c
