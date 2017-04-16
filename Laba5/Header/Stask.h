//
// Created by Глеб Линник on 09.12.16.
//

#ifndef STACK_H
#define STACK_H

#include "List.h"

typedef struct Stack {
    List *value;
    struct Stack *next;
} Stack;

int push(Stack **, int);
int pop(Stack **);
int watch(Stack *);
void printStack(Stack *);
void clearStack(Stack **);

#endif //STACK_H
