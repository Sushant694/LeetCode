// Problem Number 21
// Merge_Two_Sorted_List

#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* Merge(Node* List1, Node* List2);
void Print(Node* head);

int main() {

    // First List
    Node* List1 = new Node(1);
    List1->next = new Node(3);
    List1->next->next = new Node(5);

    // Second List
    Node* List2 = new Node(2);
    List2->next = new Node(4);
    List2->next->next = new Node(6);

    Node* Result = Merge(List1, List2);

    Print(Result);
    return 0;
}

Node* Merge(Node* List1, Node* List2) {
    // Let's create a Dummy Node
    Node dummy(0);    // This is a List
    Node* tail = &dummy;    // Passing Reference 
    // loop through the L1 and L2
    while(List1 != nullptr && List2 != nullptr) {
        if(List1->val < List2->val) {
            tail->next = List1;
            List1 = List1->next;
        }
        else {
            tail->next = List2;
            List2 = List2->next;
        }
        // also update the tail
        tail = tail->next;
    }

    // Also remaining Nodes
    if(List1 != nullptr) {
        tail->next = List1;
    }
    else {
        tail->next = List2;
    }
    return dummy.next;
}

void Print(Node* head) {

    while(head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}