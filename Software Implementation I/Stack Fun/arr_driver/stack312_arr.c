
#include <stdio.h>
#include <stdbool.h>
#include "stack_arr.h"
#include <stdlib.h>
#include <string.h>


void makeStack(Stack312 *s){
    s -> top = NULL;
}

bool isFull(Stack312 s){
    return false;
}

bool isEmpty(Stack312 s){
    return (s.top == NULL);
}

void push(StackEntry e,Stack312 *s){
    s -> top += 1;
    s -> elements[s -> top] = e;
};

StackEntry pop(Stack312 *s){
    s -> top -= 1;
    return (s -> elements[(s -> top)+1]);
};



