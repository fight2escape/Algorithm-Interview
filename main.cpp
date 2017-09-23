#include <iostream>
#include "Linked-List/203. Remove Linked List Elements.h"

using namespace std;

int main() {
    int arr[] = {1,1,2};
    int size = sizeof(arr)/sizeof(int);
    ListNode *head = CreateLinkedList(arr,size);
    PrintLinkedList(head);

    ListNode *res = Solution().removeElements(head,1);

    PrintLinkedList(res);
    DeleteLinkedList(res);

    return 0;
}