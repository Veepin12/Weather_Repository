#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void  no_pair(vector<int> & arr){
    
    unordered_map<int,int> m;
    vector<int> num;


    for (auto i:arr){
        m[arr[i]]++;


    }
    for(auto i :m){
        int ele=INT_MIN;
        if(m.find(ele)!=m.end()) {
        cout<<i.first<<","<<i.second<<endl;
    }
        
    }
    
    
  

}




int main(){
    vector<int> arr={1,1,12,3,4,4,3,2,1};
  
    no_pair(arr);
  
    


}