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

void Reverse(Node* &head){

    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;

    while(current != NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;

}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    display(head);

    Reverse(head);

    cout << "AFter reversing "<< endl;
    display(head);
}