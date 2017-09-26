//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_PRIORITY_QUEUE_H
#define ALGORITHM_INTERVIEW2_PRIORITY_QUEUE_H

#include <iostream>
#include <queue>
#include <ctime>
#include <vector>
#include <functional>

using namespace std;

bool myCmp(int a,int b){
    return a%10 > b%10;
}

/**
 * 自定义比较函数
 */
void testPriorityQueue3(){
    priority_queue<int, vector<int>, function<bool(int,int)>> pq(myCmp);
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int num = rand() % 100;
        pq.push(num);
        cout<<"insert "<<num<<endl;
    }
    while( !pq.empty() ){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

/**
 * 最小堆
 */
void testPriorityQueue2(){
    priority_queue<int, vector<int>, greater<int>> pq;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int num = rand() % 100;
        pq.push(num);
        cout<<"insert "<<num<<endl;
    }
    while( !pq.empty() ){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

/**
 * 最大堆
 */
void testPriorityQueue1(){
    priority_queue<int> pq;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int num = rand()%100;
        pq.push(num);
        cout<<"insert "<<num<<endl;
    }
    while( !pq.empty() ){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

#endif //ALGORITHM_INTERVIEW2_PRIORITY_QUEUE_H
