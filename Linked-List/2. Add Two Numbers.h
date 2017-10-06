//
// Created by Shinelon on 2017/10/6.
//

#ifndef ALGORITHM_INTERVIEW2_2_ADD_TWO_NUMBERS_H
#define ALGORITHM_INTERVIEW2_2_ADD_TWO_NUMBERS_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2, *preP1 = nullptr;
        int carry=0, sum;

        if(!p1){ return p2; }
        if(!p2){ return p1; }

        while(p1 && p2){
            sum = p1->val + p2->val + carry;
            carry = sum / 10;
            p1->val = sum % 10;

            preP1 = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        if(!p1){
            p1 = p2;
            preP1->next = p1;
        }
        while(p1){
            sum = p1->val + carry;
            carry = sum/10;
            p1->val = sum % 10;
            preP1 = p1;
            p1 = p1->next;
        }

        if(carry){
            preP1->next = new ListNode(carry);
        }
        return l1;
    }
};

class Test{
public:
    void test(){
        int arr1[] = {2,4,9};
        int size1 = sizeof(arr1)/sizeof(int);
        int arr2[] = {5,6,4};
        int size2 = sizeof(arr2)/sizeof(int);
        ListNode* p1 = CreateLinkedList(arr1, size1);
        ListNode* p2 = CreateLinkedList(arr2, size2);

        ListNode* res = Solution().addTwoNumbers(p1, p2);
        PrintLinkedList(res);
    }
};

#endif //ALGORITHM_INTERVIEW2_2_ADD_TWO_NUMBERS_H
