//
// Created by Shinelon on 2017/10/12.
//

#ifndef ALGORITHM_INTERVIEW2_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define ALGORITHM_INTERVIEW2_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead, *cur = pre->next;
        while(cur && cur->next){
            if(cur->val == cur->next->val){
                ListNode* del;
                do{
                    del = cur->next;
                    cur->next = del->next;
                    delete del;
                    del = NULL;
                }while(cur->next && cur->val==cur->next->val);
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,1,1,3,4};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        PrintLinkedList( Solution().deleteDuplicates(head) );
    }
};

#endif //ALGORITHM_INTERVIEW2_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
