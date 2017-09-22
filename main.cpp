#include <iostream>
#include <string>
#include <vector>
#include "125. Valid Palindrome.h"


using namespace std;

int main() {
//    int arr[] = {1,2,3,4,5,6,7}, target = 8;
//    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//    vector<int> res = Solution().twoSum(vec, target);
//
//    for(int i=0; i<res.size(); i++){
//        cout<<res[i]<<" ";
//    }

    string s = "A man, a plan, a canal: Panama";
    string s1 = ".,";
    string s2 = "aA";
    string s3 = "0P";
    string s4 = "ab2a";
    string s5 = "a.";
    bool res1 = Solution().isPalindrome(s1);
    bool res2 = Solution().isPalindrome(s2);
    bool res3 = Solution().isPalindrome(s3);
    bool res4 = Solution().isPalindrome(s4);
    bool res5 = Solution().isPalindrome(s5);
    cout<<"isPalindrome : "<< res1 <<endl;
    cout<<"isPalindrome : "<< res2 <<endl;
    cout<<"isPalindrome : "<< res3 <<endl;
    cout<<"isPalindrome : "<< res4 <<endl;
    cout<<"isPalindrome : "<< res5 <<endl;


    return 0;
}