//
// Created by Shinelon on 2017/10/11.
//

#ifndef ALGORITHM_INTERVIEW2_数字构造_H
#define ALGORITHM_INTERVIEW2_数字构造_H


#include <iostream>
#include <vector>
using namespace std;

vector<int> getRes(int s, bool flag){
    int a, b;
    if(flag){
        a = 1;
        b = 2;
    }else{
        a = 2;
        b = 1;
    }
    vector<int> res;
    flag = true;
    while(s){
        if(flag && s - a >= 0){
            res.push_back(a);
            s -= a;
            flag = false;
        }else if(!flag && s - b >= 0){
            res.push_back(b);
            flag = true;
            s -= b;
        }
    }
    return res;
}

int main(){
    int s = 0;
    while(cin>> s){
        vector<int> res;
        res = getRes(s, s%3==1);
        for(auto r : res){
            cout<<r;
        }
        cout<<endl;
    }
}



#endif //ALGORITHM_INTERVIEW2_数字构造_H
