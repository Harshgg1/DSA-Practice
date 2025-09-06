#include <iostream>
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

// Insert at head
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert at tail
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position
void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    if(pos == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Delete node
void deleteNode(int pos, Node* &head) {
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;

        while(count < pos && curr != NULL) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr == NULL) return; // out of range
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Print linked list
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtHead(head, 5);
    insertAtPosition(head, tail, 3, 15);

    print(head);

    deleteNode(3, head);
    print(head);

    return 0;
}
