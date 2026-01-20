#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class solution{
   
   
 public:

     void merge(vector<int> & arr,int left,int mid,int right){
    int n1=mid - left +1;
    int n2= right - mid;

    vector<int> L(n1),R(n2);

    for(int i=0;i<n1;i++){
        L[i]=arr[left + i];


    }
    for(int j=0; j<n2 ; j++){
        R[j] = arr[mid +1+j];
    }

    int i=0;
    int j=0; int k=left;

    while(i<n1 && j<n2)
    {
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;

        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){

        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
       }
    }
     void mergesort(vector<int> & arr,int left,int right){
    if(left>=right){return;}

    int mid = left + (right- left)/2;

    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);

    merge(arr,left,mid,right);


     }

    //quick Sort algorithm;


     int partition(vector<int> & arr,int low,int high){
        int pivot=arr[high];

        int i=low -1;

        for(int j=low;j<=high-1;j++){
            if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
            }

        }



    swap(arr[i+1],arr[high]);
    return (i+1);
    }
    void quicksort(vector<int> & arr,int low,int high){
        if(low<high){
            

            int pi =partition(arr,low,high);

            quicksort(arr,low,pi-1);
            quicksort(arr,pi+1,high);
        }
    }

    

};
int main(){
    class solution s;

    vector<int> arr={23,56,76,98,232,24};
    int n= arr.size();


    s.mergesort(arr,0,n-1);
    for(auto i: arr){
        cout<<i<<",";
    }

    cout<<endl;

    s.quicksort(arr,0,n-1);

    for(auto i: arr){
        cout<<i<<",";
    }

}