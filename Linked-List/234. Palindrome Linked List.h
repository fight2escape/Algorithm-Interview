//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_234_PALINDROME_LINKED_LIST_H
#define ALGORITHM_INTERVIEW2_234_PALINDROME_LINKED_LIST_H

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
     * 双指针同时走，步长分别为1和2，找到中点后，对后半段进行翻转，然后对两段进行遍历比较即可
     * @param head
     * @return
     */
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left = dummy, *right = dummy;
        while(right->next != NULL && right->next->next!=NULL){
            left = left->next;
            right = right->next->next;
        }
        left->next = reverseLinkedList(left->next);
        left = left->next;
        ListNode *newl = left;
        while(head != left){
            if(head->val != newl->val){
                return false;
            }
            head = head->next;
            newl = newl->next;
        }
        return true;
    }

    ListNode* reverseLinkedList(ListNode* cur){
        ListNode* pre = NULL, *next = NULL;
        while(cur!=NULL){
            next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

#endif //ALGORITHM_INTERVIEW2_234_PALINDROME_LINKED_LIST_H
//int arr[] = {1,2,1};
//int size = sizeof(arr)/sizeof(int);
//ListNode *head = CreateLinkedList(arr,size);
//PrintLinkedList(head);
//
//bool res = Solution().isPalindrome(head);
//cout<<"res:"<<res<<endl;