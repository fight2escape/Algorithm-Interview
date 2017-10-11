//
// Created by Shinelon on 2017/10/11.
//

#ifndef ALGORITHM_INTERVIEW2_序列操作_H
#define ALGORITHM_INTERVIEW2_序列操作_H

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        unordered_map<int,bool> map;
        map.clear();
        int res[100001] = {0};
        int v[100001] = {0};
        for(int i=1; i<=n; i++){
            v[i] = i;
        }
        int tmp;
        int ri = 0;
        while(m--){
//            cin>>tmp;
            scanf("%d", &tmp);
            v[tmp] = 0;
            map[tmp] = true;
            res[ri++] = tmp;
        }
        for(int i=ri-1; i>=0; i--){
            if(map[res[i]]){
                map[res[i]] = false;
//                cout<<res[i]<<endl;
                printf("%d\n",res[i]);
            }
        }
        for(int i=1; i<=n; i++){
            if(v[i]){
//                cout<<v[i]<<endl;
                printf("%d\n",v[i]);
            }
        }
        cout<<endl;
    }
}

#endif //ALGORITHM_INTERVIEW2_序列操作_H
