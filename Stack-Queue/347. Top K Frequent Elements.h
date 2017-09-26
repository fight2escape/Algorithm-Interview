//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_347_TOP_K_FREQUENT_ELEMENTS_H
#define ALGORITHM_INTERVIEW2_347_TOP_K_FREQUENT_ELEMENTS_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto n : nums){
            map[n] ++;
        }
        // greater根据pair<int,int>中的first进行比较
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(auto m : map){
            if( pq.size() == k ){
                if( pq.top().first < m.second ){
                    pq.pop();
                    pq.push( make_pair(m.second, m.first) );
                }
            }else{
                pq.push( make_pair(m.second, m.first) );
            }
        }

        vector<int> res;
        stack<int> stk;
        while( !pq.empty() ){
            stk.push(pq.top().second);
            pq.pop();
        }
        while( !stk.empty() ){
            int tmp = stk.top();
            res.push_back(tmp);
            stk.pop();
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_347_TOP_K_FREQUENT_ELEMENTS_H
//vector<int> vec = {1,1,1,2,2,3};
//int k = 2;
//vector<int> res = Solution().topKFrequent(vec,k);
//
//for(auto r : res){
//cout<<r<<" ";
//}
//cout<<endl;