// Stack implementation using a linked list

#include <iostream>


class Node {
    // Node class represents an element in the stack
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}

class Stack{
    // Stack class represents the stack data structure
    private:
        Node* top;
        int length; 

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            length = 1;
        }

    
    void push(int value) {
        // Create a new node with the given value
        Node* newNode = new Node(value);
        // Link the new node to the current top of the stack
        newNode->next = top;
        // Update the top pointer to the new node
        top = newNode;
        length++;
    }
    int pop() {
        // Check if the stack is empty
        if (length == 0) return INT_MIN; // Return INT_MIN to indicate that the stack is empty

        // Store the current top node in a temporary variable
        Node* temp = top;
        int poppedValue = temp->value;

        // Move the top pointer to the next node
        top = top->next;

        // Delete the old top node and decrement the length
        delete temp;
        length--;

        return poppedValue;
    }
    int size() {
        // Return the current size of the stack
        return length;
    }
    bool isEmpty() {
        // Check if the stack is empty
        return length == 0;
    }

    int top(){
        // Check if the stack is empty
        if (length == 0) return INT_MIN; // Return INT_MIN to indicate that the stack is empty

        // Return the value of the top node
        return top->value;
    }
}