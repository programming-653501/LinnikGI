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

int push(Stack **, List *);
List * pop(Stack **);
List * watch(Stack *);
void clearStack(Stack **);

#endif //STACK_H
