//
// Created by Shinelon on 2017/10/4.
//

#ifndef ALGORITHM_INTERVIEW2_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define ALGORITHM_INTERVIEW2_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    // 数字键盘映射
    vector<string> letterMap = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


public:
    /**
     * 递归法
     * @param digits
     * @return
     */
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.empty()){
            return res;
        }

        findCombinations(digits, 0, "");
        return res;
    }
private:
    vector<string> res;
    /**
     * 记录[0,index]中的可能情况拼接到s上，等递归到底时，保存该条结果到res中
     * @param digits
     * @param index
     * @param s
     */
    void findCombinations(string digits, int index, string s){
        if(index == digits.size()){
            res.push_back(s);
            return;
        }

        int indexMap = digits[index]-'0';
        // 数字1为空，直接进入下一个数，否则无法进入for循环递归到底
        if(indexMap == 1){
            findCombinations(digits, index+1, s);
        }else{
            string letters = letterMap[indexMap];
            for(auto letter : letters){
                findCombinations(digits, index+1, s + letter);
            }
        }
        return;
    }

public:
    /**
     * 迭代法
     * @param digits
     * @return
     */
    vector<string> letterCombinations1(string digits) {
        vector<string> res, tmp;
        for(auto dg : digits){
            if(res.empty()){
                res.push_back("");
            }
            for(auto letter : letterMap[ dg-'0' ]){
                for(auto r : res){
                    tmp.push_back(r + letter);
                }
            }
            if(!tmp.empty()){
                res = tmp;
            }
            tmp.clear();
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
//    string digits = "";
//    string digits = "223456789223";
//
//    time_t start = clock();
//    vector<string> res = Solution().letterCombinations(digits);
//    time_t end = clock();
//
//    double spendTime = double(end-start)/(double)CLOCKS_PER_SEC;
//    cout<<res.size()<<endl;
//    cout<<"spendTime: "<<spendTime<<endl;

//    for(auto r : res){
//        cout<<r<<endl;
//    }