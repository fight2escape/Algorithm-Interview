//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_24_SWAP_NODES_IN_PAIRS_H
#define ALGORITHM_INTERVIEW2_24_SWAP_NODES_IN_PAIRS_H

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead, *cur, *next;
        while(pre->next != NULL){
            cur = pre->next;
            if(cur->next == NULL){
                break;
            }
            next = cur->next;

            cur->next = next->next;
            next->next = cur;
            pre->next = next;

            pre = cur;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};

#endif //ALGORITHM_INTERVIEW2_24_SWAP_NODES_IN_PAIRS_H
