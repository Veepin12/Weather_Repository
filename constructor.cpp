#include <iostream>
using namespace std;

class solution{

    public:
    solution(){

    }
    int  temp(int tempArr[],int n){

        int Min=INT_MAX;
        int Max=INT_MIN;

        int t1=tempArr[0];
        for(int i=0;i<n;i++){

            Max=max(Max,tempArr[i]);
            Min=min(Min,tempArr[i]);


        }
        cout<<"The Max and Min Temprature is"<<Max<<"And"<<Min;
        return 0;
    }
};
int main(){
        int n;
        cin>>n;
        int tempArr[n];
        for(int i=0;i<n;i++){
            cin>>tempArr[i];
        }

        class solution S;

        S.temp(tempArr,n);

        cout<<endl;

        for(int i=0 ; i<n ; i++){
            cout<<tempArr[i]<<" ,";
        }

}