//
//  main.c
//  Singly_Linked_List
//
//  Created by Han Sol Lee on 9/19/16.
//  Copyright © 2016 Solly. All rights reserved.
//

#include <stdio.h>
#include "Singly_Linked_List.h"

int setAscOrder(int d1, int d2) {
    if(d1 < d2)
        return 0;   // pred to move forward
    else
        return 1;   // get pred position
}

int main(int argc, const char * argv[]) {
    // insert code here...
    List list;
    int data;
    ListInit(&list);
    
    SetSortRule(&list, setAscOrder);
    
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);
    
    
    printf("current num of data: %d: \n", LCount(&list));
    if(LFirst(&list, &data)){
        printf("%d ", data);
        
        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    
    if(LFirst(&list, &data)) {
        if(data == 22)
            LRemove(&list);
        while(LNext(&list, &data)) {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    printf("current num of data: %d: \n", LCount(&list));
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        
        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    return 0;
}
