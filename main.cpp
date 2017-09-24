#include <iostream>
#include "Linked-List/234. Palindrome Linked List.h"
using namespace std;

int main() {
    int arr[] = {1,2,1};
    int size = sizeof(arr)/sizeof(int);
    ListNode *head = CreateLinkedList(arr,size);
    PrintLinkedList(head);

    bool res = Solution().isPalindrome(head);
    cout<<"res:"<<res<<endl;
//    PrintLinkedList(res);
//    DeleteLinkedList(res);


    return 0;
}