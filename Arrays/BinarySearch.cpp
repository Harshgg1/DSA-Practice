#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int a) {
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;

    while(start<=end){
        if(a==arr[mid]){
            return mid;
        }
        if(a>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter number to search  ";
    cin>>n;

    int arr[6]={1,4,7,9,13,17};

    int index=BinarySearch(arr,6,n);

    cout<<"Index of "<<n<< " is "<<index<<endl;

}