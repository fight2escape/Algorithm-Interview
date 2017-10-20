//
// Created by Shinelon on 2017/10/20.
//

#ifndef ALGORITHM_INTERVIEW2_49_GROUP_ANAGRAMS_H
#define ALGORITHM_INTERVIEW2_49_GROUP_ANAGRAMS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(map.find(tmp) != map.end()){
                map[tmp].push_back(str);
            }else{
                map[tmp] = vector<string>{str};
            }
        }
        vector<vector<string>> res;
        for(auto iter = map.begin(); iter!=map.end(); ++iter){
            res.push_back(iter->second);
        }
        return res;
    }
};

class Test{
public:
    void test(){
        vector<string> strs = {};
        for(auto res : Solution().groupAnagrams(strs)){
            for(auto r : res){
                cout<<r<<" ";
            }
            cout<<endl;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_49_GROUP_ANAGRAMS_H
