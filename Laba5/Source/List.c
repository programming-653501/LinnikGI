//
// Created by Глеб Линник on 05.04.17.
//
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/List.h"


void push_front(List **list, char *content) {
    insertAtIndex(list, content, 0);
}

void deleteItem(List **list, List *item) {
    if(!item)
        return;

    if(item->next)
        item->next->previous = item->previous;

    if(item->previous) {
        item->previous->next = item->next;
    } else {
        *list = item->next;
    }

    free(item->content);
    free(item);
}

List *findInList(List *list, char *content) {
    while(list) {
        if (strcmp(list->content, content))
            return list;
        list = list->next;
    }
    return NULL;
}

List *clearList(List *list) {
    List* temp;
    while(list) {
        temp = list;
        list = list->next;
        free(temp->content);
        free(temp);
    }

    return NULL;
}

void insertAtIndex(List **list, char *content, int index) {
    List *item = (List *)malloc(sizeof(List));

    if (!item)
        exit(-1);

    item->content = (char *)malloc(sizeof(char) * (strlen(content) + 1));
    strcpy(item->content, content);

    if (!*list) {
        *list = item;
        (*list)->next = NULL;
        (*list)->previous = NULL;
    } else {
        List *temp = *list;
        for (int i = 1; i <= index; ++i) {
            temp = temp->next;
        }
        item->previous = temp->previous;
        if (item->previous)
            item->previous->next = item;
        temp->previous = item;
        item->next = temp;
    }
}
