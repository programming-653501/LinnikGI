//
// Created by Глеб Линник on 05.04.17.
//

#ifndef LIST_H
#define LIST_H

typedef struct List {
    struct List *next;
    struct List *previous;
    char *content;
} List;

void push_front(List **, char *);
void insertAtIndex(List **, char *, int);
void deleteItem(List **, List *);
List *findInList(List *, char *);
List *clearList(List*);

#endif //LIST_H
