//
// Created by Глеб Линник on 05.04.17.
//
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/List.h"

List *init() {
    //Creating the last node
    List *lastNode = (List *)malloc(sizeof(List));
    lastNode->content = NULL;
    lastNode->previous = NULL;
    lastNode->next = NULL;
    return lastNode;
}

void push_front(List **list, char *content) {
    insertAtIndex(list, content, 0);
}

void deleteItem(List **list, List *item) {
    if(!item || !item->next)
        return;

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
    List **temp = &list;
    while(list) {
        if (!strcmp(list->content, content))
            return *temp;
        (*temp) = (*temp)->next;
    }
    return NULL;
}

List *clearList(List **list) {
    List* temp;
    while((*list)->next) {
        temp = *list;
        *list = (*list)->next;
        (*list)->previous = NULL;
        free(temp->content);
        free(temp);
    }

    return *list;
}

void deleteList(List **list) {
    free(clearList(list));
}

int insertAtIndex(List **list, char *content, int index) {
    if (!*list)
        return -1;

    List *newNode = (List *)malloc(sizeof(List));

    if (!newNode)
        exit(-1);

    newNode->content = (char *)malloc(sizeof(char) * (strlen(content) + 1));
    strcpy(newNode->content, content);

    List *tempNode = *list;
    for (int i = 1; i <= index; ++i) {
        if (!tempNode)
            return -1; //Returns if wrong index was passed
        tempNode = tempNode->next;
    }
    if (tempNode->previous)
        tempNode->previous->next = newNode;
    newNode->previous = tempNode->previous;
    newNode->next = tempNode;
    tempNode->previous = newNode;
    if (!newNode->previous)
        *list = newNode;
    return 0;
}