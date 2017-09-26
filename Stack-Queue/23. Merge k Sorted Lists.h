//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_23_MERGE_K_SORTED_LISTS_H
#define ALGORITHM_INTERVIEW2_23_MERGE_K_SORTED_LISTS_H

#include <iostream>
#include <vector>
#include <queue>
#include "../Linked-List/CreateLinkedList.h"

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                pq.push( make_pair(lists[i]->val, lists[i]));
            }
        }
        if( pq.empty() ){ return NULL; }

        ListNode* res = new ListNode(0);
        ListNode* cur = new ListNode(NULL);
        res->next = cur;

        while( !pq.empty() ){
            ListNode *min = pq.top().second;
            pq.pop();

            cur->val = min->val;
            min = min->next;
            if(min != NULL){
                pq.push( make_pair(min->val, min) );
            }
            if( !pq.empty() ){
                cur->next = new ListNode(NULL);
                cur = cur->next;
            }
        }
        cur = res->next;
        delete res;
        return cur;
    }
};

#endif //ALGORITHM_INTERVIEW2_23_MERGE_K_SORTED_LISTS_H
//int vec1[] = {};
//int vec2[] = {1,3};
//int vec3[] = {4,5,6};
//int k1 = sizeof(vec1)/sizeof(int);
//int k2 = sizeof(vec2)/sizeof(int);
//int k3 = sizeof(vec3)/sizeof(int);
//ListNode *head1 = CreateLinkedList(vec1, k1);
//ListNode *head2 = CreateLinkedList(vec2, k2);
//ListNode *head3 = CreateLinkedList(vec3, k3);
//vector<ListNode*> vec = {head1, head2, head3};
//
//ListNode* res = Solution().mergeKLists(vec);
//while(res!=NULL){
//cout<<res->val<<"->";
//res = res->next;
//}
//cout<<"NULL"<<endl;