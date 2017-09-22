#include <iostream>
#include <string>
#include <vector>
#include "345. Reverse Vowels of a String345..h"


using namespace std;

int main() {
//    int arr[] = {1,2,3,4,5,6,7}, target = 8;
//    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//    vector<int> res = Solution().twoSum(vec, target);
//
//    for(int i=0; i<res.size(); i++){
//        cout<<res[i]<<" ";
//    }

    string s2 = "hello";
    string s3 = "leetcode";
    string s4 = "hEllo";
    string s5 = "leEtcode";
    string res2 = Solution().reverseVowels(s2);
    string res3 = Solution().reverseVowels(s3);
    string res4 = Solution().reverseVowels(s4);
    string res5 = Solution().reverseVowels(s5);
    cout<<"reverse to : "<< res2 <<endl;
    cout<<"reverse to : "<< res3 <<endl;
    cout<<"reverse to : "<< res4 <<endl;
    cout<<"reverse to : "<< res5 <<endl;


    return 0;
}