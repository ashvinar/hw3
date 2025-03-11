#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

    if (!head){
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    struct Node* temp = head;
    head = head->next;

    llpivot(head, smaller, larger, pivot);


    if (temp->val <= pivot){
        temp->next = smaller;
        smaller = temp;
    }else{
        temp->next = larger;
        larger = temp;
    }
       
}
