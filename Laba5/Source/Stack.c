//
// Created by Глеб Линник on 09.12.16.
//

#include "../Header/Stask.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int push(Stack **stack, int value) {
    int res = 1;

    Stack *newElement = (Stack*)malloc(sizeof(Stack));

    if (newElement == NULL) {
        res = 0;
    } else {
        newElement->value = value;
        newElement->next = *stack;
        *stack = newElement;
    }

    return res;
}

int pop(Stack **stack) {
    //assert(*stack != (*stack)->start);

    int value = (*stack)->value;
    Stack *temp = (*stack)->next;
    free((*stack));
    *stack = temp;

    return value;
}

int watch(Stack *stack) {
    return stack->value;
}

void printStack(Stack *stack) {
    if (stack->next == NULL)
        return;
    while (stack) {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

void clearStack(Stack **stack) {
    while (*stack) {
        pop(stack);
    }
}

