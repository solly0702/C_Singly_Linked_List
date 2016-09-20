//
//  Singly_Linked_List.c
//  Singly_Linked_List
//
//  Created by Han Sol Lee on 9/19/16.
//  Copyright © 2016 Solly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Singly_Linked_List.h"

void ListInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist, listData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    
    (plist->numOfData)++;
}

void SInsert(List *plist, listData data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head;
    newNode->data = data;
    
    // to find the position of newNode->data
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }
    
    newNode->next = pred->next;
    pred->next=newNode;
    
    (plist->numOfData)++;
}

void LInsert(List *plist, listData data) {
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, listData *pdata) {
    if(plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, listData *pdata) {
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

listData LRemove(List *plist) {
    Node *rpos = plist->cur;
    listData rdata = rpos->data;
    
    plist->before->next=plist->cur->next;
    plist->cur=plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(listData d1, listData d2)) {
    plist->comp = comp;
}
