#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;


    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }

    ~Node()
    {
        int value = data;

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory freed from data with value-> " << value << endl;
    }
};

void insertathead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        head->prev = temp;
        temp->next =  head;
        head = temp;
    }
}

void insertattail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail-> next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertatmid(Node* &head, Node* &tail, int d, int pos){
    if(pos == 1){
        insertattail(head,tail,d);
        return;
    }

    int count = 1;
    Node* temp = head;
    while( count < pos && temp != NULL){
        count ++;
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertattail(head, tail, d);
        return;
    }
    
    Node* insert = new Node(d);
    insert->next = temp->next;
    insert->prev = temp;
    temp->next->prev = insert;
    temp->next = insert;

}

void DeleteNode(Node* &head, Node* &tail, int pos){
        if (head == NULL) return;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL; // list became empty
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        int count = 1;

        while (count < pos && curr != NULL) {
            curr = curr->next;
            count++;
        }

        if (curr == NULL) return; // out of range

        curr->prev->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev; // deleting last node
        }
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;


}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertathead(head, tail, 10);
    insertathead(head, tail, 5);
    insertattail(head, tail, 20);
    insertattail(head, tail, 25);
    insertatmid(head, tail, 15, 3);

    cout << "Doubly Linked List: ";
    print(head);

    DeleteNode(head, tail, 3);
    cout << "After deleting position 3: ";
    print(head);


    return 0;

}