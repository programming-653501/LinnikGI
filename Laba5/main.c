#include <stdio.h>
#include "Header/Stask.h"

void reversePrintList(List *list);

int main() {
    List *list = init();
    push_front(&list, "Char");
    push_front(&list, "Bash");
    push_front(&list, "Hello");
    push_front(&list, "World");

    reversePrintList(list);

    Stack *stack = NULL;
    push(&stack, list);

    list = init();
    push_front(&list, "Top");
    push_front(&list, "Coders");
    push_front(&list, "JetBrains");
    push_front(&list, "Xcode");

    reversePrintList(list);

    push(&stack, list);

    return 0;
}

void reversePrintList(List *list) {
    if (list->next) {
        reversePrintList(list->next);
        printf("%s ", list->content);
    }
}