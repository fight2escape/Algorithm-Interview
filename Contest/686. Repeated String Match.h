//
// Created by Shinelon on 2017/10/1.
//

#ifndef ALGORITHM_INTERVIEW2_686_REPEATED_STRING_MATCH_H
#define ALGORITHM_INTERVIEW2_686_REPEATED_STRING_MATCH_H

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int time = B.size()%A.size()==0 ? B.size() / A.size() : B.size()/A.size()+1;
        string tmp = A;
        for(int i=0; i<time; i++){
            A += tmp;
        }

        if(A.find(B) != string::npos){
            return A.find(B)==0 ? time : time+1;
        }
        return -1;
    }
};

#endif //ALGORITHM_INTERVIEW2_686_REPEATED_STRING_MATCH_H
//    string A = "abcabcabcabc";
//    string B = "abac";
//    string A = "abcd";
//    string B = "cdabcdab";
//string A="a";
//string B="aa";
//int res = Solution().repeatedStringMatch(A,B);
//cout<<res<<endl;