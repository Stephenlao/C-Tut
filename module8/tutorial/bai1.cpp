// lam lai bai 1 linked list
#if 1
#include <iostream>
using std::cout;
using std::cin;


class Node {
    private:
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;

    public:
        Node(int value = 0) : value(value) {};

        // setter for connect links
        void setLinks(Node* next, Node* prev) {
            this->next = next;
            this->prev = prev;
        }

        friend void printForwardLL(Node* head);
        friend void printBackwardLL(Node* tail);
        friend void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode);
        friend void deleteNode(Node *&head, Node *&tail, Node *delNode);
        friend void swapNode(Node *&head, Node *&tail, Node *first, Node *second);
        friend void sortNode(Node *&head, Node* tail);
};

void printForwardLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->value << "--->";
        curr = curr->next;
    }
};

void printBackwardLL(Node* tail) {
    Node* curr = tail;
    while (curr != nullptr) {
        cout << curr->value << "--->";
        curr = curr->prev;
    }
};

void insertNode(Node *&head, Node *&tail, Node *priorNode, Node *newNode) {
    if (priorNode == nullptr) {
        newNode->next = head;
        head->next->prev = newNode;
        head = newNode;
    } else {
        newNode->next = priorNode->next;
        priorNode->next->prev = newNode;

        priorNode->next = newNode;
        newNode->prev = priorNode;
        
        if (tail == priorNode) {
            tail = newNode;
        }
    }
};

void deleteNode(Node *&head, Node *&tail, Node *delNode) {
    if (head == delNode) {
        head = delNode->next;
        head->prev = nullptr;
        delNode->next = nullptr;
    } else if (tail == delNode) {
        tail = delNode->prev;
        tail->next = nullptr;
        delNode->prev = nullptr;
    } else {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delNode->prev = delNode->next = nullptr;
    }
};

void swapNode(Node *&head, Node *&tail, Node *first, Node *second) {
    second->prev = first->prev;
    first->prev = second;
    first->next = second->next;
    second->next = first;

    if (head != first) {
        second->prev->next = second;
    } else {
        head = second;
    }

    if (tail != second) {
        first->next->prev = first;
    } else {
        tail = first;
    }
};

void sortNode(Node *&head, Node* tail) {
    Node* curr = head;

    int count = 0;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    for (int i = (count-1); i > 0; i--) {
        curr = head;
        for (int j = 0; j < i; j++) {
            if (curr->value > curr->next->value) {
                swapNode(head,tail, curr, curr->next);
            } else {
                curr = curr->next;
            }
        }
    }
}

int main() {
    // a
    Node node1(8), node2(5), node3(3), node4(6);

    Node* head = &node1; // create a normal pointer to store address of node1 (head)

    node1.setLinks(&node2, nullptr);
    node2.setLinks(&node3, &node1);
    node3.setLinks(&node4, &node2);
    node4.setLinks(nullptr, &node3);

    Node* tail = &node4;

    cout << "Linked list forward: " << "\n";
    printForwardLL(head);
    cout << "\n";

    cout <<"Linked list backward: " << "\n";
    printBackwardLL(tail);
    cout << "\n";

    // b insert node
    Node node5(100), node6(200);

    // because delete memory address of linked list using &
    insertNode(head,tail,nullptr, &node5);
    insertNode(head,tail,&node3, &node6);
    deleteNode(head,tail,&node2);

    cout << "Linked list after insert and delete node: " << "\n";
    printForwardLL(head);
    cout << "\n";


    //(c) swap the last two nodes
    swapNode(head, tail, &node6, &node4);

    cout << "After swapping nodes.\n";
    printForwardLL(head);
    cout <<"\n";
    printBackwardLL(tail);
    cout <<"\n";


     //(d) sort the linked list
    sortNode(head, tail);
    cout << "After sorting.\n";
    printForwardLL(head);
    return 0;
}

#endif