//
// Created by Shinelon on 2017/10/19.
//

#ifndef ALGORITHM_INTERVIEW2_445_ADD_TWO_NUMBERS_II_H
#define ALGORITHM_INTERVIEW2_445_ADD_TWO_NUMBERS_II_H

#include "CreateLinkedList.h"
#include <stack>

class Solution {
public:
    /**
     * 使用栈实现
     * @param l1 
     * @param l2
     * @return
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        ListNode *cur1 = l1, *cur2 = l2, *cur = nullptr;

        while(cur1){
            stk1.push(cur1->val);
            cur1 = cur1->next;
        }
        while(cur2){
            stk2.push(cur2->val);
            cur2 = cur2->next;
        }

        int carry = 0, sum = 0;
        while(!stk1.empty() || !stk2.empty()){
            int n1 = 0, n2 = 0;
            if(!stk1.empty()){
                n1 = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                n2 = stk2.top();
                stk2.pop();
            }
            sum = n1 + n2 + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = cur;
            cur = node;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = cur;
            cur = node;
        }
        return cur;
    }



    /**
     * 先逆序再求解最后再逆序
     */
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkList(l1);
        l2 = reverseLinkList(l2);
        return reverseLinkList(addTwoLinkList(l1, l2));
    }

private:
    ListNode* reverseLinkList(ListNode* head){
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }
        head = pre;
        return head;
    }

    ListNode* addTwoLinkList(ListNode* l1, ListNode* l2){
        auto *dummy = new ListNode(0);
        auto *cur = dummy;
        int add = 0, sum = 0;

        while(l1 && l2){
            sum = l1->val + l2->val + add;
            add = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* rest = l1 ? l1 : l2;
        while(rest){
            sum = rest->val + add;
            add = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            rest = rest->next;
        }

        if(add){
            cur->next = new ListNode(add);
        }
        cur = dummy->next;
        return cur;
    }
};

class Test{
public:
    void test(){
        int arr1[] = {7,2,4,3};
        int n1 = sizeof(arr1)/sizeof(int);
        ListNode* l1 = CreateLinkedList(arr1, n1);
        int arr2[] = {5,6,4};
        int n2 = sizeof(arr2)/sizeof(int);
        ListNode* l2 = CreateLinkedList(arr2, n2);
        PrintLinkedList(Solution().addTwoNumbers(l1,l2));
    }
};

#endif //ALGORITHM_INTERVIEW2_445_ADD_TWO_NUMBERS_II_H
