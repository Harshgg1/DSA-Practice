#include<iostream>
#include<map>
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

bool Detectloop(Node* &head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool>visited;

    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp]  = true;
        temp = temp->next;
        
    }
    return false;
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
    
    head->next->next->next->next->next->next->next->next = head;
    
    // Display(head);

    bool ans = Detectloop(head);
    cout << ans;

    




}