//
// Created by Shinelon on 2017/10/17.
//

#ifndef ALGORITHM_INTERVIEW2_房间人数分配_H
#define ALGORITHM_INTERVIEW2_房间人数分配_H

#include<iostream>
#include <vector>

using namespace std;
int main(){
    int n, x;
    while(cin>>n>>x){
        vector<int> room;
        int tmp;
        for(int i=0; i<n; i++){
            scanf("%d", &tmp);
            room.push_back(tmp);
        }
        x -= 1;
        int num = 0;

        while(true){
            if(--room[x] < 0){
                break;
            }
            num++;
            if(--x < 0) x = n-1;
        }

        room[x] = num;
        for(int i=0; i<n; i++){
            if(i>0) printf(" ");
            printf("%d",room[i]);
        }
        printf("\n");
    }
    return 0;
}

#endif //ALGORITHM_INTERVIEW2_房间人数分配_H
