//
// Created by Shinelon on 2017/10/7.
//

#ifndef ALGORITHM_INTERVIEW2_684_REDUNDANT_CONNECTION_H
#define ALGORITHM_INTERVIEW2_684_REDUNDANT_CONNECTION_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent = vector<int>(1000, 0);
        for(int i=0; i<=1000; i++){
            parent[i] = i;
        }
        for(auto edge : edges){
            if(find(edge[0]) == find(edge[1])){
                return edge;
            }else{
                unionElements(edge[0], edge[1]);
            }
        }
        return {};
    }
private:
    vector<int> parent;
    int find(int p){
        if(p != parent[p]){
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }
    void unionElements(int p, int q){
        int parentP = find(p);
        int parentQ = find(q);
        if(parentP == parentQ) return ;
        parent[parentQ] = parentP;
        return ;  
    }
};

class Test{
public:
    void test(){
        vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}};
        vector<int> res = Solution().findRedundantConnection(edges);
        if(!res.empty()){
            cout<<"[ "<<res[0]<<" ,"<<res[1]<<" ]"<<endl;
        }else{
            cout<<"[]"<<endl;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_684_REDUNDANT_CONNECTION_H
