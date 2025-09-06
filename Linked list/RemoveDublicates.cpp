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

Node* Removedublicate(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;

    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* forward = curr->next->next;
            Node* nodetodelete = curr->next;
            nodetodelete ->next = NULL;
            
            curr->next = forward;
            delete (nodetodelete);
        }
        else
        curr = curr->next;
    }
    return head;
}

void Display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
        Node* head = new Node(15);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next ->next= new Node(30);
    head->next->next->next->next = new Node(35);
    head->next->next ->next->next->next= new Node(35);
    head->next->next->next->next->next->next = new Node(45);
    head->next->next->next->next->next->next->next = new Node(50);

    Display(head);

    Removedublicate(head);

    Display(head);
}