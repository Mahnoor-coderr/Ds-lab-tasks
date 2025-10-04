#include <iostream>
using namespace std;

struct Node {
    int PassengerID;
    Node* next;
    Node(int id) {
        PassengerID = id;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* headPtr;

public:
    LinkedList() {
        headPtr = nullptr;
    }

    ~LinkedList() {
        Node* curr = headPtr;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        cout << "\nPassenger list cleared from memory.\n";
    }

    void insertAtStart(int id) {
        Node* newNode = new Node(id);
        newNode->next = headPtr;
        headPtr = newNode;
    }

    void insertAtEnd(int id) {
        Node* newNode = new Node(id);

        if (headPtr == nullptr) {
            headPtr = newNode;
            return;
        }

        Node* curr = headPtr;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void insertAtPosition(int id, int pos) {
        if (pos == 0) {
            insertAtStart(id);
            return;
        }

        Node* curr = headPtr;
        for (int i = 0; curr != nullptr && i < pos - 1; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Position out of range, inserting at end.\n";
            insertAtEnd(id);
            return;
        }

        Node* newNode = new Node(id);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteFromStart() {
        if (headPtr == nullptr) {
            cout << "Passenger list is empty.\n";
            return;
        }
        Node* temp = headPtr;
        headPtr = headPtr->next;
        delete temp;
    }

    void showList() {
        Node* curr = headPtr;
        cout << "\nPassenger List: ";
        while (curr != nullptr) {
            cout << curr->PassengerID << " -> ";
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList PassengerList;

    PassengerList.insertAtStart(101);
    PassengerList.insertAtEnd(102);
    PassengerList.insertAtEnd(103);
    PassengerList.showList();

    PassengerList.insertAtStart(999);
    PassengerList.showList();

    PassengerList.insertAtPosition(555, 2);
    PassengerList.showList();

    PassengerList.deleteFromStart();
    PassengerList.showList();

    return 0;
}
