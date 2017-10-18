//
// Created by Shinelon on 2017/10/18.
//

#ifndef ALGORITHM_INTERVIEW2_25_REVERSE_NODES_IN_K_GROUP_H
#define ALGORITHM_INTERVIEW2_25_REVERSE_NODES_IN_K_GROUP_H

#include "CreateLinkedList.h"
#include <vector>

class Solution {
public:

    /**
     * 递归
     * @param head
     * @param k
     * @return
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;
        int count = 0;
        ListNode* nextHead = head;
        while(nextHead && count!=k){
            nextHead = nextHead->next;
            ++count;
        }
        if(count < k) return head;
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        pre = reverseKGroup(nextHead, k);
        while(count-- > 0){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    /**
     * 迭代，将各个分组逆序后连接头尾
     * @param head
     * @param k
     * @return
     */
    ListNode* reverseKGroup1(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 0;
        while(cur){
            ++count;
            cur = cur->next;
        }
        if(k<=1) return head;
        count = count - count%k;
        if(count==0) return head;

        int index = 0;
        cur = head;
        vector<ListNode*> tail, newHead;
        ListNode *pre = nullptr, *next=cur->next;

        while(index<count){
            if(index % k == 0){
                ListNode* tmp = cur;
                tail.push_back(tmp);
                pre = nullptr;
            }else if((index+1) % k == 0){
                ListNode* tmp = cur;
                newHead.push_back(tmp);
            }

            cur->next = pre;
            pre = cur;
            cur = next;
            if(next){
                next = next->next;
            }
            ++index;
        }
        if(cur){
            ListNode* tmp = cur;
            newHead.push_back(tmp);
        }

        for(int i=1; i<newHead.size(); ++i){
            tail[i-1]->next = newHead[i];
        }
        head = newHead[0];
        return head;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,3,4,5};
        int n = sizeof(arr)/sizeof(int);
        ListNode* head = CreateLinkedList(arr, n);
        int k = 5;
        PrintLinkedList( Solution().reverseKGroup(head, k) );
    }
};
#endif //ALGORITHM_INTERVIEW2_25_REVERSE_NODES_IN_K_GROUP_H
