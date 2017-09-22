//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_125_VALID_PALINDROME_H
#define ALGORITHM_INTERVIEW2_125_VALID_PALINDROME_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 自定义判断函数和转换函数
     * @param s
     * @return
     */
    bool isPalindrome(string s) {
        int st = 0, en = s.length()-1;
        while(st < en){
            while(st<en && !isAlNum(s[st])){ st++; }
            while(st<en && !isAlNum(s[en])){ en--; }
            if(lCase(s[st]) == lCase(s[en])){
                st++;
                en--;
            }else{
                return false;
            }
        }
        return true;
    }

    bool isAlNum(char ch) {
       return (ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    }

    char lCase(char ch) {
        return ch>='A' && ch<='Z' ? ch-'A'+'a' : ch;
    }

    /**
     * 包含数字和字母
     * 使用系统提供的判断函数和转换函数
     * @param s
     * @return
     */
    bool isPalindrome1(string s) {
        int len = s.length();
        if(len < 2){
            return true;
        }
        int i = 0, j = len-1;
        while(i < j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(j>i && !isalnum(s[j])){
                j--;
            }

            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};

#endif //ALGORITHM_INTERVIEW2_125_VALID_PALINDROME_H
//string s = "A man, a plan, a canal: Panama";
//string s1 = ".,";
//string s2 = "aa";
//string s3 = "0P";
//string s4 = "ab2a";
//string s5 = "a.";
//bool res1 = Solution().isPalindrome(s1);
//bool res2 = Solution().isPalindrome(s2);
//bool res3 = Solution().isPalindrome(s3);
//bool res4 = Solution().isPalindrome(s4);
//bool res5 = Solution().isPalindrome(s5);
//cout<<"isPalindrome : "<< res1 <<endl;
//cout<<"isPalindrome : "<< res2 <<endl;
//cout<<"isPalindrome : "<< res3 <<endl;
//cout<<"isPalindrome : "<< res4 <<endl;
//cout<<"isPalindrome : "<< res5 <<endl;