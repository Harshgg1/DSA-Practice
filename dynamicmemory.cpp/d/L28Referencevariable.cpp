#include<iostream>
using namespace std;

// pass by value
void update(int n){
    n++;
}

//pass by reference
void update2(int& n){
    n++;
}


int main(){
    int n=5;

    //1 box has now two names if m will increase than n also
    int& m = n;
    m++;


    cout << "before--> "<< n << endl;
    update2(n);
    cout << "After --> "<< n << endl;
}