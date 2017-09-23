#include <iostream>
#include "Search(Set-Map)/220. Contains Duplicate III.h"


using namespace std;

int main() {
    vector<int> vec = {-2147483648,-2147483647};
    int k = 3;
    int v = 3;
    bool res = Solution().containsNearbyAlmostDuplicate(vec,k,v);
    cout<<"res:"<<res<<endl;

    return 0;
}