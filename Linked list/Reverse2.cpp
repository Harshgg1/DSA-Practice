#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

void Reverse(Node* &head, Node* &curr, Node* &prev){

    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    curr->next = prev;
    Reverse(head, forward, curr);

    

}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void Reverselinkedlist(Node* &head){

    Node* curr = head;
    Node* prev = NULL;

    Reverse(head, curr, prev);
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head->next->next->next->next = new Node(30);
    display(head);

    Reverselinkedlist(head);

    cout << "AFter reversing "<< endl;
    display(head);

}
