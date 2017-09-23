#include <iostream>
#include "Search(Set-Map)/219. Contains Duplicate II.h"


using namespace std;

int main() {

    vector<int> vec = {1,2,1};
    int k = 1;

    bool res = Solution().containsNearbyDuplicate(vec,k);

    cout<<"res:"<<res<<endl;

    return 0;
}