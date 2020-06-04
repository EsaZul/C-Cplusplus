
#include <stdio.h>
#include <stdbool.h>
#include "stack_arr.h"
#include <string.h>
#include <stdlib.h>

#define BUFSIZ 100

/*typedef struct Node{
    char *line;
    struct Bode *next;
}Node;
*/


int main(int argc, char *argv[]) {

    /*declare and initialise variable*/
    char fName[] = "equation.txt";
    strcpy(fName,argv[1]);
    FILE *fptr = NULL;
    fptr = fopen(fName, "r");
    char exp[BUFSIZ];

    Stack312 s2;
    makeStack(&s2);
    int i = 0;
    int j = 0;
    int numCols;
    while (fgets(exp, BUFSIZ, fptr)) {
        for (i = 0; &exp[i] != NULL; i++) {
            if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{') || (exp[i] == '<')) {
                if (!isFull(s2)) {
                    push(exp[i], &s2);
                } else {                      //Debugger: Notifies if Stack is Full
                    printf("\nFULL!");
                }
            } else if ((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}') || (exp[i] == '>')) {
                if (isEmpty(s2)) {                                   //checks if eqn starts w/ closed bracket
                    if (exp[i] == ')') {
                        printf("\n%s === missing (", exp);
                        i = 0;
                        fgets(exp, BUFSIZ, fptr);
                    } else if (exp[i] == ']') {
                        printf("\n%s === missing [", exp);
                        i = 0;
                        fgets(exp, BUFSIZ, fptr);
                    } else if (exp[i] == '}') {
                        printf("\n%s === missing {", exp);
                        i = 0;
                        fgets(exp, BUFSIZ, fptr);
                    } else if (exp[i] == '>') {
                        printf("\n%s === missing <", exp);
                        i = 0;
                        fgets(exp, BUFSIZ, fptr);
                    }
                } else {
                    if (s2.elements[s2.top] == '(') {
                        if (exp[i] == ')') {
                            pop(&s2);
                        } else {
                            printf("\n%s === missing )", exp);
                            i = 0;
                            fgets(exp, BUFSIZ, fptr);
                        }
                    } else if (s2.elements[s2.top] == '[') {
                        if (exp[i] == ']') {
                            pop(&s2);
                        } else {
                            printf("\n%s === missing ]", exp);
                            i = 0;
                            fgets(exp, BUFSIZ, fptr);
                        }
                    } else if (s2.elements[s2.top] == '{') {
                        if (exp[i] == '}') {
                            pop(&s2);
                        } else {
                            printf("\n%s === missing}", exp);
                            i = 0;
                            fgets(exp, BUFSIZ, fptr);
                        }
                    } else if (s2.elements[s2.top] == '<') {
                        if (exp[i] == '>') {
                            pop(&s2);
                        } else {
                            printf("\n%s === missing >", exp);
                            i = 0;
                            fgets(exp, BUFSIZ, fptr);
                        }
                    }
                }
            }
        }
        if (isEmpty(s2)) {
            printf("\n%s === valid expression", exp);
        } else {
            if (s2.elements[s2.top] == '(') {
                printf("\n%s === missing )", exp);
            } else if (s2.elements[s2.top] == '[') {
                printf("\n%s === missing ]", exp);
            } else if (s2.elements[s2.top] == '{') {
                printf("\n%s === missing }", exp);
            } else if (s2.elements[s2.top] == '<') {
                printf("\n%s === missing >", exp);
            }
        }
    }
}




/*          Stack debugger
int main() {
    printf("Hello, World!\n");

    Stack312 s2;
    makeStack(&s2);

    if (isEmpty(s2))
        printf("empty\n");
    else
        printf("not empty\n");

    StackEntry p2 = 'p';
    StackEntry p3 = 'g';

    if(!isFull(s2)) {
        push(p2, &s2);
        push(p3, &s2);
    }
    else {
        printf("FULL!\n");
    }


    if (isEmpty(s2))
        printf("again empty\n");
    else
        printf("again not empty\n");

    StackEntry p;
    p = pop(&s2);
    printf("pop 1: %c\n", p);
    p = pop(&s2);
    printf("pop 2: %c \n", p);

    return 0;
}
*/






