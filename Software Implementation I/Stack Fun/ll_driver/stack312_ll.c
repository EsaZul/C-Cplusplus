#include <stdio.h>
#include <stdbool.h>
#include "stack_ll.h"
#include <stdlib.h>
#include <string.h>


void makeStack(Stack312 *s) {
    s->top = NULL;
}

bool isFull(Stack312 s) {
    return false;
}

bool isEmpty(Stack312 s) {
    return (s.top == NULL);
}

void push(StackEntry e,Stack312 *s) {
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    temp->next = s->top;
    s->top = temp;
    temp->pixel = e;
};

StackEntry pop(Stack312 *s) {
    StackNode *ptr = s->top;
    Pixel p = s->top->pixel;
    s->top = s->top->next;
    free(ptr);
    return p;
};