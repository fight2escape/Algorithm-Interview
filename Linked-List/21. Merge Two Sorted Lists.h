//
// Created by Shinelon on 2017/10/17.
//

#ifndef ALGORITHM_INTERVIEW2_21_MERGE_TWO_SORTED_LISTS_H
#define ALGORITHM_INTERVIEW2_21_MERGE_TWO_SORTED_LISTS_H

#include "CreateLinkedList.h"

class Solution {
public:

    /**
     * 递归版
     * @param l1
     * @param l2
     * @return
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    /**
     * 手动迭代
     * @param l1
     * @param l2
     * @return
     */
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        auto *dummy = new ListNode(INT32_MIN);
        dummy->next = l2;
        ListNode* cur  = dummy, *next = l1->next;
        while(l1 && cur){
            if(cur->next){
                if(l1->val >= cur->val && l1->val < cur->next->val){
                    l1->next = cur->next;
                    cur->next = l1;
                    cur = l1;
                    l1 = next;
                    if(next){
                        next = next->next;
                    }
                }else{
                    cur = cur->next;
                }
            }else{
                cur->next = l1;
                break;
            }
        }
        l2 = dummy->next;
        delete dummy;
        return l2;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,1,1};
        int arr2[] = {2,3,7,8};
        int n = sizeof(arr)/sizeof(int);
        int n2 = sizeof(arr2)/sizeof(int);
        ListNode* l1 = CreateLinkedList(arr, n);
        ListNode* l2 = CreateLinkedList(arr2, n2);
        ListNode* res = Solution().mergeTwoLists(l1, l2);
        PrintLinkedList(res);
    }
};

#endif //ALGORITHM_INTERVIEW2_21_MERGE_TWO_SORTED_LISTS_H
