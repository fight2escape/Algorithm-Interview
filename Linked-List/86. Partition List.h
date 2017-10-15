//
// Created by Shinelon on 2017/10/15.
//

#ifndef ALGORITHM_INTERVIEW2_86_PARTITION_LIST_H
#define ALGORITHM_INTERVIEW2_86_PARTITION_LIST_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        auto *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *edit = dummy, *pre, *cur;
        while(edit->next && edit->next->val < x){
            edit = edit->next;
        }
        if(!edit->next) return head;

        pre = edit->next;
        cur = pre->next;
        while(cur){
            if(cur->val < x){
                pre->next = cur->next;
                cur->next = edit->next;
                edit->next = cur;
                edit = cur;
            }else{
                pre = cur;
            }
            cur = pre->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,4,3,2,5,2};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        int k = 3;
        PrintLinkedList( Solution().partition(head, k) );
    }
};
#endif //ALGORITHM_INTERVIEW2_86_PARTITION_LIST_H
