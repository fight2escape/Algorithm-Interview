//
// Created by Shinelon on 2017/10/16.
//

#ifndef ALGORITHM_INTERVIEW2_328_ODD_EVEN_LINKED_LIST_H
#define ALGORITHM_INTERVIEW2_328_ODD_EVEN_LINKED_LIST_H

#include "CreateLinkedList.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head, *pre, *cur;
        if(odd && odd->next && odd->next->next) {
            pre = odd->next;
            cur = pre->next;
        }else{
            return head;
        }
        while(true){
            pre->next = cur->next;
            cur->next = odd->next;
            odd->next = cur;
            odd = cur;

            if(pre->next && pre->next->next){
                pre = pre->next;
                cur = pre->next;
            }else{
                break;
            }
        }
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,3,4,5};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        PrintLinkedList( Solution().oddEvenList(head) );
    }
};

#endif //ALGORITHM_INTERVIEW2_328_ODD_EVEN_LINKED_LIST_H
