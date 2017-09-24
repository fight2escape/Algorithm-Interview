//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define ALGORITHM_INTERVIEW2_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include "CreateLinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 遍历一次，设置两个指针，两指针需要N+1次移动才能重合
     * @param head
     * @param n
     * @return
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n<=0){
            n = 1;
        }
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead, *end = pre;
        for(int i=0; i<=n && end!=NULL; i++){
            end = end->next;
        }

        while(end != NULL){
            pre = pre->next;
            end = end->next;
        }
        ListNode *cur = pre->next;
        pre->next = cur->next;
        delete cur;
        head = newHead->next;
        delete newHead;
        return head;
    }

    /**
     * 两次遍历
     * @param head
     * @param n
     * @return
     */
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        int num = 0;
        ListNode *cur = head;
        while(cur != NULL){
            num++;
            cur = cur->next;
        }
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead;
        for(int i=0; i<num-n; i++){
            pre = pre->next;
        }
        cur = pre->next;
        pre->next = cur->next;
        delete cur;

        head = newHead->next;
        delete newHead;
        return head;
    }
};

#endif //ALGORITHM_INTERVIEW2_19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
//int arr[] = {1,2,3};
//int size = sizeof(arr)/sizeof(int);
//ListNode *head = CreateLinkedList(arr,size);
//PrintLinkedList(head);
//
//ListNode *res = Solution().removeNthFromEnd(head,-5);
//
//PrintLinkedList(res);
//DeleteLinkedList(res);