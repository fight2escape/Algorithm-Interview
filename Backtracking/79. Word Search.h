//
// Created by Shinelon on 2017/10/5.
//

#ifndef ALGORITHM_INTERVIEW2_79_WORD_SEARCH_H
#define ALGORITHM_INTERVIEW2_79_WORD_SEARCH_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return word.empty();
        }
        width = board.size();
        length = board[0].size();
        visited = vector<vector<bool>>(width, vector<bool>(length, false));
        for(int i=0; i<width; i++){
            for(int j=0; j<length; j++){
                if(searchWord(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<bool>> visited;
    int length, width;
    vector<vector<int>> director = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool searchWord(const vector<vector<char>>& board, const string &word, int index, int startx, int starty){
        if(index == word.size()-1){
            return word[index] == board[startx][starty];
        }
        if(word[index] == board[startx][starty]){
            visited[startx][starty] = true;
            for(int i=0; i<4; i++){
                int newx = startx + director[i][0];
                int newy = starty + director[i][1];
                if(inArray(newx, newy) && !visited[newx][newy]){
                    if(searchWord(board, word, index+1, newx, newy)){
                        return true;
                    }
                }
            }
            visited[startx][starty] = false;
        }
        return false;
    }

    bool inArray(int x, int y) {
        return x>=0 && x<width && y>=0 && y<length;
    }
};

class Test{
public:
    void test(){
        vector<vector<char>> vec = {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
        };
        string word = "ABCCED";
//        string word = "SEE";
//        string word = "ABCB";
//        string word = "";
        cout<< Solution().exist(vec, word) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_79_WORD_SEARCH_H
