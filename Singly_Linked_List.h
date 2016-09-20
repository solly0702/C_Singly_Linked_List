//
//  Singly_Linked_List.h
//  Singly_Linked_List
//
//  Created by Han Sol Lee on 9/19/16.
//  Copyright © 2016 Solly. All rights reserved.
//

#ifndef Singly_Linked_List_h
#define Singly_Linked_List_h

#define TRUE 1
#define FALSE 0

typedef int listData;

typedef struct _node {
    listData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
    int (*comp)(listData d1, listData d2);
} LinkedList;


typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, listData data);

int LFirst(List *plist, listData *data);
int LNext(List *plist, listData *data);

listData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(listData d1, listData d2));

#endif /* Singly_Linked_List_h */
