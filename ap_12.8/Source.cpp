#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

void addNode(Node*& head, string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void removeNode(Node*& head, Node* target) {
    if (target == NULL || head == NULL) {
        return;
    }
    if (target->prev != NULL) {
        target->prev->next = target->next;
    }
    if (target->next != NULL) {
        target->next->prev = target->prev;
    }
    if (target == head) {
        head = head->next;
    }
    delete target;
}

void printList(Node* head) {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

bool hasCircularNext(Node* head) {
    Node* temp = head;
    do {
        if (temp->next->data == temp->data) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

void removeNodesWithSameNeighbors(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* current = head;
    do {
        if (current->data == current->next->data) {
            Node* toDelete = current;
            current = current->next;
            removeNode(head, toDelete);
        }
        else {
            current = current->next;
        }
    } while (current->next != head);

    if (head->data == head->next->data) {
        removeNode(head, head);
    }
}

int main() {
    Node* head = NULL;
    string line;
    ifstream myfile("input.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            addNode(head, line);
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file" << endl;
        return 0;
    }

    cout << "Original list: ";
    printList(head);

    if (hasCircularNext(head)) {
        cout << "At least one element is equal to its next element in the circular list." << endl;
    }
    else {
        cout << "No element is equal to its next element in the circular list." << endl;
    }

    removeNodesWithSameNeighbors(head);

    cout << "Modified list after removing elements with same neighbors: ";
    printList(head);

    return 0;
}
