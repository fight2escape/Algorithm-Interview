//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_345_REVERSE_VOWELS_OF_A_STRING345_H
#define ALGORITHM_INTERVIEW2_345_REVERSE_VOWELS_OF_A_STRING345_H

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 搜索到后在进行交换操作
     * 提问：元音是否包含'y'
     * @param s
     * @return
     */
    string reverseVowels(string s) {
        int st = 0, end = s.length()-1;
        while(st < end){
            while(st<end && !isVowels(s[st])){ st++; }
            while(st<end && !isVowels(s[end])){ end--; }
            swap(s[st++], s[end--]);
        }
        return s;
    }

    /**
     * 字符串搜索慢些，使用switch运行更快
     * @param ch
     * @return
     */
    bool isVowels(char ch) {
//        string vowels = "aeiouAEIOU";
//        return vowels.find(ch) != string::npos;
        switch(ch){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_345_REVERSE_VOWELS_OF_A_STRING345_H
//string s2 = "hello";
//string s3 = "leetcode";
//string s4 = "hEllo";
//string s5 = "leEtcode";
//string res2 = Solution().reverseVowels(s2);
//string res3 = Solution().reverseVowels(s3);
//string res4 = Solution().reverseVowels(s4);
//string res5 = Solution().reverseVowels(s5);
//cout<<"reverse to : "<< res2 <<endl;
//cout<<"reverse to : "<< res3 <<endl;
//cout<<"reverse to : "<< res4 <<endl;
//cout<<"reverse to : "<< res5 <<endl;