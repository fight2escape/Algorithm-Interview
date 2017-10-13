//
// Created by Shinelon on 2017/10/13.
//

#ifndef ALGORITHM_INTERVIEW2_147_INSERTION_SORT_LIST_H
#define ALGORITHM_INTERVIEW2_147_INSERTION_SORT_LIST_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        auto *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* cmp=newHead, *pre = newHead->next, *cur=pre->next;
        while(cur){
            while(cmp != pre && cmp->next->val < cur->val){
                cmp = cmp->next;
            }
            if(cmp != pre){
                pre->next = cur->next;
                cur->next = cmp->next;
                cmp->next = cur;
            }else{
                pre = cur;
            }

            cur = pre->next;
            cmp = newHead;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {4,1,5,8,6};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        PrintLinkedList( Solution().insertionSortList(head) );
    }
};

#endif //ALGORITHM_INTERVIEW2_147_INSERTION_SORT_LIST_H
