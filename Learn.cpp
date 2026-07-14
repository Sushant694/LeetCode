// Linked List

#include <iostream>

// Create Node
class Node {
    public: 
        int value;
        Node * next;
        // Constructor
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

// Linked List
class LinkedList {
    private: 
        Node * head;
        Node * tail;
        int length;
    public:
        // Constructor
        LinkedList(int value) {
            Node * newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        // Printing the List
        void PrintList() {
            Node * temp = head;
            while(temp) {
                std::cout << temp->value << " ";
                temp = temp->next;
            }
        }

        // Append
        void Append(int value) {
            Node * newNode = new Node(value);
            if(head != nullptr) {    // means list is not empty
                tail->next = newNode;
                tail = newNode;
            } else {
                head = newNode;
                tail = newNode;
            }
            length++;
        }

        // Delete Last
        void Delete_Last() {
            // when there is no number in list
            if(length == 0) return;
            Node * temp = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node * pre = head;
                while(temp->next != nullptr) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        // Prepend
        void Prepend(int value) {
            Node * newNode = new Node(value);
            // Let's say list is empty
            if(length == 0) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        // Delete First
        void Delete_First() {
            if(length == 0) return;
            Node * temp = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

        // Function to get the value
        Node * get(int index) {
            // 1 2 3 4
            // ^
            // temp
            // 
            // Checking the edges cases 
            if(index < 0 || index > length) return nullptr;
            Node * temp = head;
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        // set function 
        bool set(int index, int value) {
            Node * temp = get(index);
            if(temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        // Insert Function
        bool Insert(int index, int value) {
            if(index < 0 || index > length) return false;
            if(index == 0) {
                Prepend(value);
                return true;
            } 
            if(index == length) {
                Append(value);
                return true;
            }
            Node * newNode = new Node(value);
            Node * temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void getHead() {
            std::cout << "Head: " << head->value << std::endl;
        }

        void getTail() {
            std::cout << "Tail: " << tail->value << std::endl;
        }

        void getLength() {
            std::cout << "Length: " << length << std::endl;
        }

};

int main() {

    LinkedList * myLinkedList = new LinkedList(10);
    myLinkedList->Append(20);
    myLinkedList->Append(30);
    myLinkedList->Append(40);
    myLinkedList->set(0, 100);
    myLinkedList->Insert(2, 200);
    myLinkedList->PrintList();
    return 0;
}