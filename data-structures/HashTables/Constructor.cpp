/** 
 * Constructor for the HashTable class.
 */

#include <iostream>
#include <string>
#include <vector>


class Node{
    public:
        std::string key;
        int value;
        Node* next;
    
        Node(std::string key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};


class HashTable {
    private:
        static const int SIZE = 7;
        Node* table[SIZE];

    public:
        int hash(std::string key){
        int hashValue = 0;
            for(int i = 0; i < key.length(); i++){
                int asciiValue = (int)key[i];
                hashValue += (hashValue + asciiValue * 23) % SIZE;
            }
            return hashValue;
        }
    void set(std::string key, int value){
        int index = hash(key);
        Node* newNode = new Node(key, value);

        if(table[index] == nullptr){
            table[index] = newNode;
        }else{
            Node* temp = table[index];
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    public:
        int get(std::string key){
        int index = hash(key);
        Node* temp = table[index];

        while(temp != nullptr){
            if(temp->key == key){
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }
    public:
    std::vector<std::string> keys(){
        std::vector<std::string> keysList;
        for(int i = 0; i < SIZE; i++){
            Node* temp = table[i];
            while(temp != nullptr){
                keysList.push_back(temp->key);
                temp = temp->next;
            }
        }
        return keysList;
    }
};