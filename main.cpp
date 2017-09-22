#include <iostream>
#include "Search(Set-Map)/454. 4Sum II.h"


using namespace std;

int main() {

    vector<int> v1 = {1,2};
    vector<int> v2 = {-2,-1};
    vector<int> v3 = {-1,2};
    vector<int> v4 = {0,2};


    int res = Solution().fourSumCount(v1,v2,v3,v4);

    cout<<"res:"<<res<<endl;

    return 0;
}