//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_BASEBALL_GAME_H
#define ALGORITHM_INTERVIEW2_BASEBALL_GAME_H

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        int round = 0;
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "+"){
                s.push_back( s.end()[-2] + s.end()[-1] );
            }else if(ops[i] == "C"){
                s.pop_back();
            }else if(ops[i] == "D"){
                s.push_back( s.back() * 2 );
            }else{
                s.push_back( (int)stod(ops[i]) );
            }
        }
        return accumulate(s.begin(), s.end(),0);
    }
};

#endif //ALGORITHM_INTERVIEW2_BASEBALL_GAME_H
////    vector<string> arr = {"-9","-40","-35","D","73"};
//vector<string> arr = {"5","2","C","D","+"};
//int res = Solution().calPoints(arr);
//cout<<"res:"<<res<<endl;