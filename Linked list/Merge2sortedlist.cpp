#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int n){
        data = n;
        next = NULL;
    }

    ~Node(){
        int value = data;
        if(this-> next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "MEMORY is freed of value --> " << value << endl;
    }
};

Node* Mergesortedlist(Node* &first, Node* &second){
    if(first == NULL){
        return second;
    }

    if(second == NULL){
        return first;
    }
}

int main(){

}