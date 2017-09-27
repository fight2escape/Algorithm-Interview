//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_120_TRIANGLE_H
#define ALGORITHM_INTERVIEW2_120_TRIANGLE_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<triangle.size(); i++){
            for(int j=0,n=triangle[i].size(); j<n; j++){
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }else if(j==triangle[i-1].size()){
                    triangle[i][j] += triangle[i-1][j-1];
                }else{
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        int min = triangle[triangle.size()-1][0];
        for(auto item : triangle[triangle.size()-1]){
            if(item < min){
                min = item;
            }
        }
        return min;
    }
};

#endif //ALGORITHM_INTERVIEW2_120_TRIANGLE_H
//vector<vector<int>> vec = { {2}, {3,4}, {6,5,7}, {4,1,8,3} };
//int res = Solution().minimumTotal(vec);
//cout<<res<<endl;