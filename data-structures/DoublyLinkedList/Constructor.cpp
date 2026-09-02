#include <iostream>

class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value; 
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

    void printList(){
        // Start from the head of the list and traverse through each node
        Node* temp = head;
        // Print the value of each node until reaching the end of the list
        while(temp != nullptr){
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    void getHead(){
        if(head != nullptr){
            std::cout << "Head: " << head->value << std::endl;
        } else {
            std::cout << "Head: nullptr" << std::endl;
        }
    }  

    void getTail(){
        if(tail != nullptr){
            std::cout << "Tail: " << tail->value << std::endl;
        } else {
            std::cout << "Tail: nullptr" << std::endl;
        }
    }

    void getLength(){
        std::cout << "Length: " << length << std::endl;
    }

    void append(int value){
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // If the list is empty, set head and tail to the new node
        if(length == 0){
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node to the end of the list
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast(){
        // Check if the list is empty
        if (length == 0) return;

        // Store the current tail node in a temporary variable
        Node* temp = tail;

        // If the list has only one node, set head and tail to nullptr
        if (length == 1){
            head = nullptr;
            tail = nullptr;  
        }else{
            // Move the tail pointer to the previous node and update its next pointer to nullptr
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--; 

    }
    void prepend(int value){
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // If the list is empty, set head and tail to the new node
        if(length == 0){
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node to the beginning of the list
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst(){
        // Check if the list is empty
        if (length == 0) return;

        // Store the current head node in a temporary variable
        Node* temp = head;

        // If the list has only one node, set head and tail to nullptr
        if (length == 1){
            head = nullptr;
            tail = nullptr;  
        }else{
            // Move the head pointer to the next node and update its prev pointer to nullptr
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--; 
    }

    Node* get(int index){
        // Check if the index is out of bounds
        if(index < 0 || index >= length) return nullptr;

        Node* temp = head;

        if(index < length / 2){
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
        } else {
            temp = tail;
            for(int i = length - 1; i > index; i--){
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if(temp != nullptr){
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        if(index < 0 || index > length) return false;
        if(index == 0) {
            prepend(value);
            return true;
        }
        if(index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;

        length++;
        return true;
    }
    bool deleteNode(int index){
        // Check if the index is out of bounds
        if(index < 0 || index >= length) return false;
        if(index == 0) {
            deleteFirst();
            return true;
        }
        if(index == length - 1) {
            deleteLast();
            return true;
        }

        // Get the node at the specified index
        Node* temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;
        length--;
        return true;
    }
};