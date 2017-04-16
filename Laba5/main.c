#include <stdio.h>
#include "Header/Stask.h"

int main() {
    List *list = NULL;
    push_front(&list, "Char");
    push_front(&list, "Bash");
    push_front(&list, "Hello");
    insertAtIndex(&list, "World", 3);

    List *item = list->next;
    deleteItem(&list, item);

    printf("%s", list->content);
    return 0;
}