//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_681_NEXT_CLOSEST_TIME_H
#define ALGORITHM_INTERVIEW2_681_NEXT_CLOSEST_TIME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> t;
        for(int i=0; i<5; i++){
            if(i != 2){
                t.push_back(stoi(time.substr(i,1)));
            }
        }

        vector<int> ts = t;
        sort(ts.begin(), ts.end());

        for(int j=0; j<4; j++){
            if(ts[j] > t[3]){
                t[3] = ts[j];
                return res(t,3,ts);
            }
        }
        for(int j=0; j<4; j++){
            if(ts[j] < 6 && ts[j] > t[2]){
                t[2] = ts[j];
                return res(t,2,ts);
            }
        }
        for(int j=0; j<4; j++){
            if((ts[0]!=2 || ts[0]==2 && ts[j]<4) && ts[j] > t[1]){
                t[1] = ts[j];
                return res(t,1,ts);
            }
        }
        for(int j=0; j<4; j++){
            if(ts[j] < 3 && ts[j] > t[0]){
                t[0] = ts[j];
                return res(t,0,ts);
            }
        }

        return res(t,-1, ts);
    }

    string res(vector<int> t,int n, vector<int> ts){
        for(int i=n+1; i<4; i++){
            t[i] = ts[0];
        }

        string res = "";
        for(int i=0; i<4; i++){
            res += to_string(t[i]);
        }
        res.insert(2,":");
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_681_NEXT_CLOSEST_TIME_H
////    string s = "19:34";
//string s = "23:59";
////    string s = "13:55";
//string res = Solution().nextClosestTime(s);
//cout<<"res:"<<res<<endl;