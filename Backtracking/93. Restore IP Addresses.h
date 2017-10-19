//
// Created by Shinelon on 2017/10/19.
//

#ifndef ALGORITHM_INTERVIEW2_93_RESTORE_IP_ADDRESSES_H
#define ALGORITHM_INTERVIEW2_93_RESTORE_IP_ADDRESSES_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear(); poss.clear();
        restore(s, 0, 4);
        return res;
    }
private:
    vector<string> res,poss;
    void restore(const string &s, const int index, const int level){
        int maxLength = (level-1)*3;
        string str;
        if(level == 1){
            for(int i=index; i<index+3 && i<s.size(); ++i){
                str += s[i];
            }
            if(!check(str)) return;
            res.push_back(poss[0]+"."+poss[1]+"."+poss[2]+"."+str);
        }else{
            for(int i=index; i<index+3 && i<s.size(); ++i){
                str += s[i];
                if(s.size()-i-1 > maxLength || s.size()-i-1 < 1) continue;
                if(!check(str)) return;
                poss.push_back(str);
                restore(s, i+1, level-1);
                poss.pop_back();
            }
        }
    }
    bool check(const string& str){
        int num = stoi(str);
        if(str.size() == 2) return num >= 10;
        else if(str.size() == 3) return num >= 100 && num <= 255;
        else return true;
    }
};

class Test{
public:
    void test(){
//        string s = "25525511135";
//        string s = "0000";
        string s = "010010";
        for(auto str : Solution().restoreIpAddresses(s)){
            cout<<str<<endl;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_93_RESTORE_IP_ADDRESSES_H
