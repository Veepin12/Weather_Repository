
#include <iostream>
#include <set>
#include <map>

using namespace std;
int main(){
    set<int> s;
    map<int,int> m;
    s.insert(10);
    s.insert(9);
    s.insert(8);
    for(auto i:s){
        cout<<i<<" ,";
    }
    cout<<endl;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    m[4]=40;
    for(auto i:m){
        cout<<i.first<<" , "<<i.second<<endl;
    }
    
}

