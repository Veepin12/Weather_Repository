#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    int arr[]={6,5,3,2,8,10,9};
    int n=sizeof(arr)/4;
    int MinCost=0;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(pq.size()>1){
        int x=pq.top(); pq.pop();
        int  y=pq.top(); pq.top();
        pq.push(x+y);
        MinCost+=(x+y);
        
    }
    cout<<MinCost;
}