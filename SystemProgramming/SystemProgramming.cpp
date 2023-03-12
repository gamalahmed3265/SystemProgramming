#include <stdio.h>
#include "t2.c"
#include "linkList.c"
#include <iostream>
using namespace std;
/*
#include <iostream>
#include<iomanip>

using namespace std;
*/
//int g = 1;

NODE* myList, node[N];
//NODE* myList, * node;
int main()
{
    int i;
    NODE* p;
    //node = (NODE*)malloc(N * sizeof(NODE)); // node->N*72 bytes in HEAP
    for (i = 0; i < N; i++) {
        
        p = &node[i];
        p->id = i;
        p->next = p + 1; // node[i].next = &node[i+1];
    }
    node[N - 1].next = 0;
    myList = &node[0]; // mylist points to node[0]
    printLinkList(myList);
    cout <<sumLinkList(myList)<<endl;
    cout << searchLinkList(myList, 3);
}




