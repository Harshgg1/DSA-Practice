#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* curr = head;
    while (curr) {
        arr.push_back(curr->data);
        curr = curr->next;
    }
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left] != arr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Helper function to insert node at end
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

int main() {
    Node* head = nullptr;
    // Example: 1->2->3->2->1
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}