#include <iostream>

class Node{
    public:
        int value;
        Node* next;

        Node(int val){
            this->value = val;
            next = nullptr;
        }

};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public: 
        // Constructor to initialize the linked list with a single node
        LinkedList(int val){
            Node* newNode = new Node(val); // Create a new node with the given value
            head = newNode;
            tail = newNode;
            length = 1;
        }
        // Destructor to clean up the linked list and free memory
        ~LinkedList(){
            Node* temp = head;
            while (temp){
                Node* nextNode = temp->next;
                delete temp; // Free the memory of the current node
                temp = nextNode; // Move to the next node
            }
        }

    void printList(){
        // Print the values of the linked list nodes
        Node* temp = head;
        while (temp){
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }

        }

    void append(int val){
        Node* newNode = new Node(val); // Create a new node with the given value

        if (length == 0){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // Link the new node to the end of the list
            tail = newNode; // Update the tail pointer to the new node
        }
        length++; // Increment the length of the linked list
    }

    void deleteLast(){
        if (length == 0) return; // If the list is empty, do nothing

        Node* temp = head;
        Node* pre = head;

        while (temp->next){
            pre = temp; // Keep track of the previous node
            temp = temp->next; // Move to the next node
        }

        tail = pre; // Update the tail pointer to the previous node
        tail->next = nullptr; // Set the next pointer of the new tail to nullptr
        delete temp; // Free the memory of the last node
        length--; // Decrement the length of the linked list

        if (length == 0){
            head = nullptr; // If the list is now empty, set head to nullptr
            tail = nullptr; // Set tail to nullptr as well
        }
    }

    void prepend(int val){
        Node* newNode = new Node(val); // Create a new node with the given value

        if (length == 0){
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head; // Link the new node to the current head
            head = newNode; // Update the head pointer to the new node
        }
        length++; // Increment the length of the linked list
    }
    void deleteFirst(){
        if (length == 0) return; // If the list is empty, do nothing

        Node* temp = head; // Store the current head node
        if (length == 1){
            delete head; // Free the memory of the only node
            head = nullptr; // Set head to nullptr
            tail = nullptr; // Set tail to nullptr
        } else {
            head = head->next; // Update the head pointer to the next node
            delete temp; // Free the memory of the old head node
        }
        length--; // Decrement the length of the linked list
    }
    Node* get(int index){
        if (index < 0 || index >= length) return nullptr; // Check for valid index

        Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next; // Traverse the list to the desired index
        }
        return temp; // Return the node at the specified index
    }

    bool set(int index, int val){
        Node* temp = get(index); // Get the node at the specified index
        if (temp){
            temp->value = val; // Update the value of the node
            return true; // Return true if the value was updated
        }
        return false; // Return false if the index is invalid
    }
    bool insert(int index, int val){
        if (index < 0 || index > length) return false; // Check for valid index

        if (index == 0){
            prepend(val); // Insert at the beginning
            return true;
        }
        if (index == length){
            append(val); // Insert at the end
            return true;
        }

        Node* newNode = new Node(val); // Create a new node with the given value
        Node* temp = get(index - 1); // Get the node before the desired index

        newNode->next = temp->next; // Link the new node to the next node
        temp->next = newNode; // Link the previous node to the new node
        length++; // Increment the length of the linked list
        return true; // Return true to indicate successful insertion
    }
    
    void deleteNode(int index){
        if (index < 0 || index >= length) return; // Check for valid index

        if (index == 0) return deleteFirst(); // Delete the first node

        if (index == length - 1) return deleteLast(); // Delete the last node

        Node* temp = get(index - 1); // Get the node before the desired index
        Node* nodeToDelete = temp->next; // Store the node to be deleted

        temp->next = nodeToDelete->next; // Link the previous node to the next node
        delete nodeToDelete; // Free the memory of the deleted node
        length--; // Decrement the length of the linked list
    }

    void reverse(){
        Node* temp = head; // Start with the head node
        head = tail; // Swap head and tail
        tail = temp;

        Node* after = temp->next; // Store the next node
        Node* before = nullptr; // Initialize the previous node as nullptr

        for (int i = 0; i < length; i++){
            after = temp->next; // Store the next node
            temp->next = before; // Reverse the link
            before = temp; // Move before to the current node
            temp = after; // Move to the next node
        }
    }
};


