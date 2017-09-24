//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_237_DELETE_NODE_IN_A_LINKED_LIST_H
#define ALGORITHM_INTERVIEW2_237_DELETE_NODE_IN_A_LINKED_LIST_H

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
    void deleteNode(ListNode* node) {

        if(node == NULL){
            return;
        }
        if(node->next == NULL){
            delete node;
            node = NULL;
            return;
        }

        ListNode *delNode = node->next;
        node->val = delNode->val;
        node->next = delNode->next;
        delete delNode;
        return;
    }
};

#endif //ALGORITHM_INTERVIEW2_237_DELETE_NODE_IN_A_LINKED_LIST_H
//int arr[] = {1,2,3};
//int size = sizeof(arr)/sizeof(int);
//ListNode *head = CreateLinkedList(arr,size);
//PrintLinkedList(head);
//
//Solution().deleteNode(head);
//
//PrintLinkedList(head);
//DeleteLinkedList(head);