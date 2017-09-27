//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_64_MINIMUM_PATH_SUM_H
#define ALGORITHM_INTERVIEW2_64_MINIMUM_PATH_SUM_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width = grid[0].size();
        int height = grid.size();
        for(int i=1; i<width; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<height; i++){
            grid[i][0] += grid[i-1][0];
        }


        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[height - 1][width - 1];
    }
};

#endif //ALGORITHM_INTERVIEW2_64_MINIMUM_PATH_SUM_H
