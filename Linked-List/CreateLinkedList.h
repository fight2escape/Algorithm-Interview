//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_CREATELINKEDLIST_H
#define ALGORITHM_INTERVIEW2_CREATELINKEDLIST_H

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateLinkedList(int arr[], int size){
    if(size <= 0){
        return NULL;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for(int i=1; i<size; i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void PrintLinkedList(ListNode *head){
    ListNode *cur = head;
    while(cur != NULL){
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << "NULL" <<endl;
    return;
}

void DeleteLinkedList(ListNode *head){
    ListNode *cur = head;
    while(cur != NULL){
        ListNode* delNode = cur;
        cur = cur->next;
        delete delNode;
    }
    return;
}

#endif //ALGORITHM_INTERVIEW2_CREATELINKEDLIST_H
