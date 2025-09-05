#include<iostream>
using namespace std;

int Sum(int *arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}


int main(){

    int n;
    cin >> n;

    int* arr = new int[5];

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }

    int ans=Sum(arr , n);
    cout <<ans;

    //delete memory from array
    delete []arr;

    ////from integer
    // delete i;

    return 0;
}