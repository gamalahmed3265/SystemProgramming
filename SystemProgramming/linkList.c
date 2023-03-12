#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10









typedef struct node {
    struct node* next;
    int id;
}NODE;

void printLinkList(NODE* p) {
    printf("[");
    while (p) {
        printf("%d, ", p->id);
        p = p->next;
    }
    printf("NULL ]\n");

}
/*
void rplist(NODE* p) {
    if (p == 0) {
        printf("NULL\n");
    }
    printf("%d, ", p->id);
    rplist(p->next);
}

*/
int sumLinkList(NODE* p) {
    return  (p == 0) ? 0 : p->id += sumLinkList(p->next);
}

NODE* searchLinkList(NODE*p,int k) {
    while (p) {
        if (p->id==k)
            return p;
        p=p->next;
    }
    return 0;
}

void insertLinkList(NODE** list, NODE* p) {
    NODE* q = *list;
    if (q == 0) // if list is empty:
        *list = p; // insert p as first element
    else { // otherwise, insert p to end of list
        while (q->next) // step to LAST element
            q = q->next;
        q->next = p; // let LAST element point to p
    }
    p->next = 0; // p is the new last element.
}
