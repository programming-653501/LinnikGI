#include <stdio.h>
#include "Header/Stask.h"

int main() {
    List *list = init();
    push_front(&list, "Char");
    push_front(&list, "Bash");
    push_front(&list, "Hello");
    insertAtIndex(&list, "World", 3);

    List *search = findInList(list, "World");
    if (search)
        search->content = "Sup";

    Stack *stack = NULL;
    push(&stack, list);
    push(&stack, list);
    push(&stack, list);
    push(&stack, list);
    push(&stack, list);
    List *check = pop(&stack);

    return 0;
}