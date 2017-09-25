//
// Created by Shinelon on 2017/9/25.
//

#ifndef ALGORITHM_INTERVIEW2_279_PERFECT_SQUARES_H
#define ALGORITHM_INTERVIEW2_279_PERFECT_SQUARES_H

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:

    /**
     * 转化为求两点的最短路径，路径长度即为返回值
     * 加入visited去掉不可能的值，性能提升10倍
     * @param n
     * @return
     */
    int numSquares(int n) {
        queue< pair<int,int> > q;
        q.push( make_pair(n, 0) );
        int visited[n] = {0};
        while( !q.empty() ){
            int num = q.front().first;
            int level = q.front().second;
            q.pop();

            for(int i=1; ; i++){
                int tmp = num-i*i;
                if(tmp < 0){
                    break;
                }else if(tmp == 0){
                    return level+1;
                }
                if(visited[tmp] == 0){
                    visited[tmp] = 1;
                    q.push( make_pair(tmp, level+1) );
                }
            }
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_279_PERFECT_SQUARES_H
//int n = 12;
//int res = Solution().numSquares(n);
//cout<<res<<endl;