//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_203_REMOVE_LINKED_LIST_ELEMENTS_H
#define ALGORITHM_INTERVIEW2_203_REMOVE_LINKED_LIST_ELEMENTS_H

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
     * 使用虚拟头结点简化操作
     * @param head
     * @param val
     * @return
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;

        ListNode *cur = preHead;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }else{
                cur = cur->next;
            }
        }
        // 记得释放内存
        head = preHead->next;
        delete preHead;

        return head;
    }

    /**
     * 不使用虚拟头结点
     * @param head
     * @param val
     * @return
     */
    ListNode* removeElements1(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode *delNode = head;
            head = delNode->next;
            delete delNode;
        }
        if(head == NULL){
            return NULL;
        }

        ListNode *cur = head;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode * delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};


#endif //ALGORITHM_INTERVIEW2_203_REMOVE_LINKED_LIST_ELEMENTS_H
//int arr[] = {1,1,2};
//int size = sizeof(arr)/sizeof(int);
//ListNode *head = CreateLinkedList(arr,size);
//PrintLinkedList(head);
//
//ListNode *res = Solution().removeElements(head,1);
//
//PrintLinkedList(res);
//DeleteLinkedList(res);