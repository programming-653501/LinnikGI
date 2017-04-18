//
// Created by Глеб Линник on 09.12.16.
//

#include "../Header/Stask.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int push(Stack **stack, List *value) {
    int res = 1;

    Stack *newElement = (Stack*)malloc(sizeof(Stack));

    if (!newElement) {
        exit(-1);
    } else {
        newElement->value = value;
        newElement->next = *stack;
        *stack = newElement;
    }

    return res;
}

List *pop(Stack **stack) {
    //assert(*stack != (*stack)->start);

    List **value = &(*stack)->value;
    Stack *temp = (*stack)->next;
    free((*stack));
    *stack = temp;

    return *value;
}

List *watch(Stack *stack) {
    return stack->value;
}

void clearStack(Stack **stack) {
    while (*stack) {
        pop(stack);
    }
}

