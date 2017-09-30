#include<iostream>
#include<iomanip>
#include "Dynamic/0-1 bag.h"

using namespace std;

int main(){

    vector<int> w = {1, 2, 3};
    vector<int> v = {6, 10, 12};
    int c = 5;
    int res = Knapsack01().knapsack01(w, v, c);
    cout<<res<<endl;

    return 0;
}