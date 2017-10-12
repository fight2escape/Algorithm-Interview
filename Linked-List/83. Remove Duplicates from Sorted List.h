//
// Created by Shinelon on 2017/10/12.
//

#ifndef ALGORITHM_INTERVIEW2_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define ALGORITHM_INTERVIEW2_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->next->val == cur->val){
                ListNode* del = cur->next;
                cur->next = del->next;
                delete del;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,1,2,2,3};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        PrintLinkedList(Solution().deleteDuplicates(head));
    }
};

#endif //ALGORITHM_INTERVIEW2_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
