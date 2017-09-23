//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_447_NUMBER_OF_BOOMERANGS_H
#define ALGORITHM_INTERVIEW2_447_NUMBER_OF_BOOMERANGS_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    /**
     * 转换为搜索表的结构
     * 表中存放的是其他所有点到某一点的距离，使用map存放，就知道同一个距离有多少个点，在求出总的可能性
     * @param points
     * @return
     */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i=0; i<points.size(); i++){
        unordered_map<int,int> map;
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                 map[dis(points[i], points[j])]++;
                }
            }
            for(unordered_map<int,int>::iterator iter = map.begin(); iter != map.end(); iter++){
                res += iter->second * (iter->second - 1);
            }
        }
        return res;
    }

    int dis(pair<int,int> p1, pair<int,int> p2){
        return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
    }

};

#endif //ALGORITHM_INTERVIEW2_447_NUMBER_OF_BOOMERANGS_H
