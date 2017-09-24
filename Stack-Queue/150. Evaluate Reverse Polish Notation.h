//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_150_EVALUATE_REVERSE_POLISH_NOTATION_H
#define ALGORITHM_INTERVIEW2_150_EVALUATE_REVERSE_POLISH_NOTATION_H

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:

    /**
     * 逆波兰式
     * 将元素从左到右依次入队，碰到运算符则取出栈顶两个元素，计算后放回栈中
     * @param rpn
     * @return
     */
    int evalRPN(vector<string>& rpn) {
        stack<int> stk;
        int fir,sec,res;
        for(auto &item : rpn){
            if(item=="+" || item=="-" || item=="*" || item=="/"){
                fir = stk.top();
                stk.pop();
                sec = stk.top();
                stk.pop();

                if(item == "+"){
                    res = sec + fir;
                }else if(item == "-"){
                    res = sec - fir;
                }else if(item == "*"){
                    res = sec * fir;
                }else{
                    res = sec / fir;
                }
                stk.push(res);
            }else{
                stk.push(stoi(item));
            }
        }
        return stk.top();
    }
};

#endif //ALGORITHM_INTERVIEW2_150_EVALUATE_REVERSE_POLISH_NOTATION_H
//vector<string> vec = {"2", "1", "+", "3", "*"};
////    vector<string> vec = {"4", "13", "5", "/", "+"};
//int res = Solution().evalRPN(vec);
//cout<<res<<endl;