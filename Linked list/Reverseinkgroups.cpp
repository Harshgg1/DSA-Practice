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

Node* ReverseKgroups(Node* &head, int k){
    //base case
    if(head == NULL){
        return NULL;
    }

    Node* forward = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;

    while(curr != NULL && count < k ){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){ 
        head->next = ReverseKgroups(forward, k);
    }
    return prev;
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
    head->next->next = new Node(25);
    head->next->next ->next= new Node(30);
    head->next->next->next->next = new Node(35);
    head->next->next ->next->next->next= new Node(40);
    head->next->next->next->next->next->next = new Node(45);
    head->next->next->next->next->next->next->next = new Node(50);
    Display(head);

    Node* ans =  ReverseKgroups(head,2);
    Display(ans);




}