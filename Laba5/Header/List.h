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


List *init();
void push_front(List **, char *);
int insertAtIndex(List **, char *, int);
void deleteItem(List **, List *);
List *findInList(List *, char *);
List *clearList(List **);
void deleteList(List **);

#endif //LIST_H
