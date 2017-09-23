//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_92_REVERSE_LINKED_LIST_II_H
#define ALGORITHM_INTERVIEW2_92_REVERSE_LINKED_LIST_II_H

#include <iostream>
#include "CreateLinkedList.h"
using namespace std;

class Solution {
public:
    /**
     * 新增一个节点指向头结点，避免m为1时带来的麻烦
     * @param head
     * @param m
     * @param n
     * @return
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode newHead(0);
        newHead.next = head;
        ListNode *firstEnd = &newHead;
        n = n-m;
        while(--m > 0){
            firstEnd = firstEnd->next;
        }
        ListNode *pre = NULL;
        ListNode *cur = firstEnd->next;
        ListNode *next = cur->next;
        while(n-- >= 0){
            cur->next = pre;
            pre = cur;
            cur = next;
            if(next!=NULL){
                next = cur->next;
            }
        }
        firstEnd->next->next = cur;
        firstEnd->next = pre;
        return newHead.next;
    }
};

#endif //ALGORITHM_INTERVIEW2_92_REVERSE_LINKED_LIST_II_H
//int arr[] = {3};
//int size = sizeof(arr)/sizeof(int);
//ListNode *head = CreateLinkedList(arr,size);
//
//ListNode *res = Solution().reverseBetween(head,1,1);
//
//PrintLinkedList(res);