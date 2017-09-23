//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_206_REVERSE_LINKED_LIST_H
#define ALGORITHM_INTERVIEW2_206_REVERSE_LINKED_LIST_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /**
     * 时间复杂度 O(n)
     * 空间复杂度 O(1)
     * @param head
     * @return
     */
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next;
        while(cur != NULL){
            next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

#endif //ALGORITHM_INTERVIEW2_206_REVERSE_LINKED_LIST_H
