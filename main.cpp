#include <iostream>
#include "Stack-Queue/23. Merge k Sorted Lists.h"
using namespace std;

int main() {

    int vec1[] = {};
    int vec2[] = {1,3};
    int vec3[] = {4,5,6};
    int k1 = sizeof(vec1)/sizeof(int);
    int k2 = sizeof(vec2)/sizeof(int);
    int k3 = sizeof(vec3)/sizeof(int);
    ListNode *head1 = CreateLinkedList(vec1, k1);
    ListNode *head2 = CreateLinkedList(vec2, k2);
    ListNode *head3 = CreateLinkedList(vec3, k3);
    vector<ListNode*> vec = {head1, head2, head3};

    ListNode* res = Solution().mergeKLists(vec);
    while(res!=NULL){
        cout<<res->val<<"->";
        res = res->next;
    }
    cout<<"NULL"<<endl;

    return 0;
}