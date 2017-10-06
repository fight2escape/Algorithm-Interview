//
// Created by Shinelon on 2017/10/6.
//

#ifndef ALGORITHM_INTERVIEW2_51_N_QUEENS_H
#define ALGORITHM_INTERVIEW2_51_N_QUEENS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);
        res.clear();
        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
private:
    vector<bool> col, dia1, dia2;
    vector<vector<string>> res;

    void putQueen(const int n,const int index, vector<int>& row){
        if(index == n){
            res.push_back( generateBoard(n, row) );
            return ;
        }
        for(int i=0; i<n; i++){
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                row.push_back(i);

                putQueen(n, index+1, row);

                row.pop_back();
                dia2[index-i+n-1] = false;
                dia1[index+i] = false;
                col[i] = false;
            }
        }
        return ;
    }

    vector<string> generateBoard(const int n, const vector<int>& row){
        vector<string> board(n, string(n, '.'));
        for(int i=0; i<n; i++){
            board[i][row[i]] = 'Q';
        }
        return board;
    }
};

#endif //ALGORITHM_INTERVIEW2_51_N_QUEENS_H
//    int n = 8;
//    vector<vector<string>> res = Solution().solveNQueens(n);
//    int i=1;
//    for(auto re : res){
//        cout<<i++<<"-------------"<<endl;
//        for(auto r : re){
//            cout<<r<<endl;
//        }
//        cout<<endl;
//    }