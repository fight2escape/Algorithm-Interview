//
// Created by Shinelon on 2017/10/5.
//

#ifndef ALGORITHM_INTERVIEW2_200_NUMBER_OF_ISLANDS_H
#define ALGORITHM_INTERVIEW2_200_NUMBER_OF_ISLANDS_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        width = grid.size();
        length = grid[0].size();
        visited = vector<vector<bool>>(width, vector<bool>(length, false));
        int res = 0;
        for(int i=0; i<width; i++){
            for(int j=0; j<length; j++){
                if(!visited[i][j] && grid[i][j]==land){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    char land = '1';
    int width, length;
    vector<vector<bool>> visited;
    vector<vector<int>> director = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    void dfs(const vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int newx = x + director[i][0];
            int newy = y + director[i][1];
            if(inArray(newx, newy) && !visited[newx][newy] && grid[newx][newy]==land){
                dfs(grid, newx, newy);
            }
        }
        return;
    }

    bool inArray(int x, int y){
        return x>=0 && x<width && y>=0 && y<length;
    }
};

#endif //ALGORITHM_INTERVIEW2_200_NUMBER_OF_ISLANDS_H
//    vector<vector<char>> vec = {
//            {'1','1','1','1','0'},
//            {'1','1','0','1','0'},
//            {'1','1','0','0','0'},
//            {'0','0','0','0','0'}
//    };
//    cout<< Solution().numIslands(vec) <<endl;