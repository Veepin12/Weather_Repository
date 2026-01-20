#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindMajorityElement(const vector<int> &arr){
    int count =0;
    int candidate =0;


    for(int num: arr){
        if(count ==0)
        {
            candidate=num;
            count=1;

        }
        else if(num == candidate ){
            count++;
        }
        else {
            count--;
        }
        
    }

      int actual_count =0;
      for(int num:arr){
         if( num == candidate){
            actual_count++;

        }
}

if(actual_count > arr.size()/2){
        return candidate;
    }
else{
        return -1; // No majority element
   }
}
int main(){
    vector<int> arr1={2,2,2,1,1,2,2,2,3,3};
    int result = FindMajorityElement(arr1);
    cout<< "Majority Element: " << result << endl;

    vector<int> arr2={1,1,1,1,1,2,3,4,5,6};
    int result2 = FindMajorityElement(arr2);
    cout<< "Majority Element: " << result2 << endl;
    return 0;
}

 