//
// Created by Shinelon on 2017/10/20.
//

#ifndef ALGORITHM_INTERVIEW2_61_ROTATE_LIST_H
#define ALGORITHM_INTERVIEW2_61_ROTATE_LIST_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *preHead = head, *end = head, *newHead = nullptr;
        int count = 0;
        while(end){
            ++count;
            end = end->next;
        }
        end = head;
        if(count){
            k=k%count;
        }

        for(int i=0; i<k; ++i){
            if(end){
                end = end->next;
            }
        }
        while(end && end->next){
            preHead = preHead->next;
            end = end->next;
        }
        if(end){
            end->next = head;
            newHead = preHead->next;
            preHead->next = nullptr;
        }
        return newHead;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,3,4,5};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        int k = 0;
        PrintLinkedList( Solution().rotateRight(head, k) );
    }
};

#endif //ALGORITHM_INTERVIEW2_61_ROTATE_LIST_H
