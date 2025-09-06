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

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

Node* Reverse(Node* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* chotahead = Reverse(head-> next);

    head->next->next = head;
    head ->next = NULL;

    return chotahead;

}

int main(){
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head->next->next->next->next = new Node(30);
    display(head);

    Node* ans = Reverse(head);

    cout << "AFter reversing "<< endl;
    display(ans);

}
