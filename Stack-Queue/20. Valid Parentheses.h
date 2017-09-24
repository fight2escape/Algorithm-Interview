//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_20_VALID_PARENTHESES_H
#define ALGORITHM_INTERVIEW2_20_VALID_PARENTHESES_H

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 括号匹配是否正确
     * @param s
     * @return
     */
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]);
            }else{
                char match;
                switch(s[i]){
                    case ')' : match = '(';break;
                    case ']' : match = '[';break;
                    case '}' : match = '{';break;
                    default  : match = ' ';
                }
                if(stk.empty() || stk.top() != match){
                    return false;
                }else{
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};

#endif //ALGORITHM_INTERVIEW2_20_VALID_PARENTHESES_H
//string s = "([]))";
//bool res = Solution().isValid(s);
//cout<<res<<endl;