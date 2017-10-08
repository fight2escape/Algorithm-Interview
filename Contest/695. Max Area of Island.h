//
// Created by Shinelon on 2017/10/8.
//

#ifndef ALGORITHM_INTERVIEW2_695_MAX_AREA_OF_ISLAND_H
#define ALGORITHM_INTERVIEW2_695_MAX_AREA_OF_ISLAND_H
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        width = grid.size();
        length = grid[0].size();
        visited = vector<vector<bool>>(width, vector<bool>(length, false));
        int res = 0;
        for(int i=0; i<width; i++){
            for(int j=0; j<length; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int size = 1;
                    findArea(grid, i, j, size);
                    res = max(res,size);
                }
            }
        }
        return res;
    }
private:
    int width, length;
    vector<vector<bool>> visited;
    vector<vector<int>> d = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    void findArea(vector<vector<int>>& grid, int startx, int starty, int& size){
        visited[startx][starty] = true;
        for(int i=0; i<4; i++){
            int newx = startx + d[i][0];
            int newy = starty + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy]==1){
                size++;
                findArea(grid, newx, newy, size);
            }
        }
    }
    bool inArea(int x, int y){
        return x>=0 && x<width && y>=0 && y<length;
    }
};

class Test{
public:
    void test(){
        vector<vector<int>> grid = {
                {0,0,1,0,0,0,0,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0}
        };
//        vector<vector<int>> grid = {
//                {1,1,0,0,0},
//                {1,1,0,0,0},
//                {0,0,0,1,1},
//                {0,0,0,1,1}
//
//        };
        cout << Solution().maxAreaOfIsland(grid) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_695_MAX_AREA_OF_ISLAND_H
