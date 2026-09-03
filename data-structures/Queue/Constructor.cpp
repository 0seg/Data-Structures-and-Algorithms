// Queue implementation in C++ using linked list

class Node {
    // Node class represents an element in the queue

    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }

}

class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;

        }
    void enqueue(int value) {
        // Create a new node with the given value
        Node* newNode = new Node(value);
        // If the queue is empty, set both first and last to the new node
        if (length == 0) {
            first = newNode;
            last = newNode;
        } else {
            // Link the current last node to the new node
            last->next = newNode;
            // Update the last pointer to the new node
            last = newNode;
        }
        length++;
    }
    int dequeue() {
        // Check if the queue is empty
        if (length == 0) return INT_MIN; // Return INT_MIN value for empty queue

        Node* temp = first; // Store the current first node
        int dequeuedValue = temp->value; // Store the value to return
        if (length == 1) {
            // If there's only one element, reset first and last to nullptr
            first = nullptr;
            last = nullptr;
        } else {
            // Move the first pointer to the next node
            first = first->next;
        }
        delete temp; // Free the memory of the dequeued node
        length--; // Decrease the length of the queue
        return dequeuedValue; // Return the value of the dequeued node
    }
}