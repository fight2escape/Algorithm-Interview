#include <iostream>
#include "Linked-List/92. Reverse Linked List II.h"
#include "Linked-List/CreateLinkedList.h"

using namespace std;

int main() {
    int arr[] = {3};
    int size = sizeof(arr)/sizeof(int);
    ListNode *head = CreateLinkedList(arr,size);

    ListNode *res = Solution().reverseBetween(head,1,1);

    PrintLinkedList(res);
    DeleteLinkedList(res);

    return 0;
}