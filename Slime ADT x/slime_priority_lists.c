
//  slime_priority_lists.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slime_priority_lists.h"
#include "slime_lists.h"
#include "slime_arenas.h"

typedef struct pl_node_ {
    void *data;
    unsigned int priority;
}pl_node;

struct pl_container_ {
    ll_node *listHead;
};

slime_arena *pl_nodeArena = NULL;

void *pl_nodeCreate(void) {
    pl_node *newPLNode = (pl_node *)malloc(sizeof(pl_node));
    if (newPLNode == NULL) {
        printf("Error allocating memory for new pl_node!!\n");
        exit(EXIT_FAILURE); }
    return newPLNode;
}

void pl_nodeInit(void *pln) {
    if (pln == NULL) {
        printf("Error! pl_nodeInit was passed NULL!\n");
        exit(EXIT_FAILURE); }
    pl_node *tmpNode = pln;
    tmpNode->data = NULL;
    tmpNode->priority = 0;
}

void pl_nodeDestroy(void *pln) {
    if (pln == NULL) {
        printf("Error! Tried to destroy a NULL pl_node!\n");
        exit(EXIT_FAILURE); }
    free(pln);
}

void pl_nodeArenaCreate(void) {
    pl_nodeArena = arenaCreate(pl_nodeCreate, pl_nodeInit, pl_nodeDestroy);
}

pl_container *priorityListCreate(void) {
    if (pl_nodeArena == NULL) pl_nodeArenaCreate();
    pl_container *newPL = (pl_container *)malloc(sizeof(pl_container));
    if (newPL == NULL) {
        printf("Error creating new priority list container!\n");
        exit(EXIT_FAILURE); }
    newPL->listHead = NULL;
    return newPL;
}

void priorityListAmend(pl_container *container,
                       void *data,
                       unsigned int priority) {
    if (container == NULL) {
        printf("Error! Tried to amend a NULL pl_container!\n");
        exit(EXIT_FAILURE); }
    pl_node *node = arenaRequest(pl_nodeArena);
    node->data = data;
    node->priority = priority;
    llPrepend(&container->listHead, node);
}

ll_node *priorityListDiscardContainer(pl_container *container) {
    if (container == NULL) {
        printf("Error! Tried to sort and discard a NULL pl_container!\n");
        exit(EXIT_FAILURE); }
    ll_node *head;
    
    return head;
}
