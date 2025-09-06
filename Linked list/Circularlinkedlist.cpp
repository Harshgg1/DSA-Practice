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

// Insert in circular LL (after element)
void insertNode(Node* &tail, int element, int d) {
    // Empty list
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp; // circular
    } else {
        Node* curr = tail;
        while(curr->data != element) {
            curr = curr->next;
            if(curr == tail) break; // element not found, avoid infinite loop
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

        if(curr == tail) {
            tail = temp; // update tail if inserted after last element
        }
    }
}

// Delete node from CLL
void deleteNode(Node* &tail, int value) {
    if(tail == NULL) return;

    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data != value) {
        prev = curr;
        curr = curr->next;
        if(curr == tail->next) return; // value not found
    }

    prev->next = curr->next;

    if(curr == prev) {
        tail = NULL; // only 1 node case
    }
    else if(curr == tail) {
        tail = prev; // deleting tail
    }

    curr->next = NULL;
    delete curr;
}

// Print circular list
void print(Node* tail) {
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 0, 10); // first element
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);

    print(tail);

    deleteNode(tail, 20);
    print(tail);

    return 0;
}
