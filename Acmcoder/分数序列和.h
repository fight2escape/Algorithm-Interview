//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_分数序列和_H
#define ALGORITHM_INTERVIEW2_分数序列和_H

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        float res = 0;
        float big = 2.0, sma = 1.0, tmp = 0;
        for(int i=0; i<a; i++){
            res +=big/sma;
            tmp = big+sma;
            sma = big;
            big = tmp;
        }
        cout<<fixed<<setprecision(4)<<res<<endl;
    }
    return 0;
}

#endif //ALGORITHM_INTERVIEW2_分数序列和_H
