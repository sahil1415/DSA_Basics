#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

// Insert at the head of the circular singly linked list
void insertAtHead(int value, Node* &head, Node* &tail) {
    Node* newNode = new Node(value);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;  // Make it circular
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;  // Update the tail's next to the new head
    }
}

// Insert at the tail of the circular singly linked list
void insertAtTail(int value, Node* &head, Node* &tail) {
    Node* newNode = new Node(value);
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;  // Make it circular
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;  // Make the tail point to head
    }
}

// Traverse the circular singly linked list
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD (Circular)" << endl;
}

// Delete a node from the circular singly linked list
void deleteFromLinkedList(int position, Node* &head, Node* &tail) {
    if (head == NULL && tail == NULL) {
        cout << "LinkedList is Empty" << endl;
        return;
    }

    if (head == tail) {  // Only one element
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        if (position == 1) {  // Deleting the head node
            Node* temp = head;
            head = head->next;
            tail->next = head;  // Update tail's next
            delete temp;
        } else {
            Node* temp = head;
            int i = 1;
            while (i < position - 1 && temp->next != head) {
                temp = temp->next;
                i++;
            }
            if (temp->next == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            if (delNode == tail) {  // Deleting the tail node
                tail = temp;
            }
            delete delNode;
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);

    insertAtTail(50, head, tail);
    insertAtTail(60, head, tail);

    traverse(head);

    deleteFromLinkedList(3, head, tail);  // Deleting the 3rd node
    traverse(head);

    deleteFromLinkedList(6, head, tail);  // Deleting the last node (tail)
    traverse(head);

    deleteFromLinkedList(1, head, tail);  // Deleting the head node
    traverse(head);

    return 0;
}
