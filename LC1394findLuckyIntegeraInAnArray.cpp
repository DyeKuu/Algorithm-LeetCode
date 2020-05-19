#include <algorithm>
#include <map>
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> a;
        for (int i = 0; i < arr.size() ; i++){
            if( a.find(arr[i]) == a.end()){
                a[arr[i]] = 1;
            }
            else{
                a[arr[i]] += 1;
            }
        }
        int res = -1;
        for(auto i = a.begin(); i != a.end(); i++){
            if (i->first == i->second){
                if (i->first > res){
                    res = i->first;
                }
            }
        }
        return res;
    }
};