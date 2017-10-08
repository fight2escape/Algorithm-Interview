//
// Created by Shinelon on 2017/10/8.
//

#ifndef ALGORITHM_INTERVIEW2_694_NUMBER_OF_DISTINCT_ISLANDS_H
#define ALGORITHM_INTERVIEW2_694_NUMBER_OF_DISTINCT_ISLANDS_H
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        width = grid.size();
        length = grid[0].size();
        visited = vector<vector<bool>>(width, vector<bool>(length, false));
        shape.clear();
        int res = 0;
        for(int i=0; i<width; i++){
            for(int j=0; j<length; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<int> p;
                    p.push_back(0);
                    findArea(grid, i, j, p);
                    if(!theSame(p)){
                        res++;
                        shape.push_back(p);
                    }
                }
            }
        }
        return res;
    }
private:
    int width, length;
    vector<vector<bool>> visited;
    vector<vector<int>> d = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<int>> shape;

    void findArea(vector<vector<int>>& grid, int startx, int starty, vector<int>& p){
        visited[startx][starty] = true;
        for(int i=0; i<4; i++){
            int newx = startx + d[i][0];
            int newy = starty + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy]==1){
                p.push_back(i);
                findArea(grid, newx, newy, p);
            }else{
                p.push_back(0);
            }
        }
    }
    bool inArea(int x, int y){
        return x>=0 && x<width && y>=0 && y<length;
    }
    bool theSame(vector<int> p){
        int size = p.size();
        for(int i=0; i<shape.size(); i++){
            if(size != shape[i].size()) continue;
            for(int j=0; j<shape[i].size(); j++){
                if(p[j] != shape[i][j]){
                    break;
                }
                if(j==shape[i].size()-1){
                    return true;
                }
            }
        }
        return false;
    }
};


class Test{
public:
    void test(){
//        vector<vector<int>> grid = {
//                {0,0,1},
//                {1,1,0}
//
//        };
//        vector<vector<int>> grid = {
//                {0,1},
//                {1,0}
//
//        };
//        vector<vector<int>> grid = {
//                {0,0,1},
//                {1,0,1}
//
//        };
//        vector<vector<int>> grid = {
//                {1,1,0,1,1},
//                {1,0,0,0,0},
//                {0,0,0,0,1},
//                {1,1,0,1,1}
//
//        };
//        vector<vector<int>> grid = {
//                {1,1,0,0,0},
//                {1,1,0,0,0},
//                {0,0,0,1,1},
//                {0,0,0,1,1}
//
//        };
        vector<vector<int>> grid = {
                {0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0},
                {0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0},
                {0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0},
                {1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1}

        };

        cout << Solution().numDistinctIslands(grid) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_694_NUMBER_OF_DISTINCT_ISLANDS_H
