#include <iostream>

using namespace std;

template <class T>
class list {
    protected:
    // public:
    T value;
    list* next;
    public:
    list(){
        this->value = NULL;
        this->next = NULL;
    }
    list(T value) {
        this->value = value;
        this->next = NULL;
    }
    protected:
    list(T value, list* p){
        this->value = value;
        this->next = p;
    }
    public:

    void add(T value) {
        if(this->next == NULL){
            this->next = new list(value);
        }
        else this->next->add(value);
    }
    void insert(T value, int i){
        if(i == 0) {
            this->next = new list(this->value, this->next);
            this->value = value;
        }
        else this->next->insert(value, i-1);
    }
    T get(int i){
        if(i == 0)
            return this->value;
        if(this->next == NULL){
            cout << "the object does not exist" << endl;
            cout << "returned the last object of linked list" << endl;
            return this->value;
        }
        else return this->next->get(i-1);
    }
    // 0-r elementiig awy gewel aldaa garna.
    // list* getNode(int i) {
    //     if(i == 1 && this->next != NULL)
    //         return this->next;
    //     else if(this->next == NULL)
    //         return NULL;
    //     else return this->next->getNode(i-1);
    // }
    // i-r elementiig ustgana
    void del(int i){
        if(i == 0){
            if(this->next == NULL) {
                cout << "there is only one node in the list" << endl;
                cout << "made the value NULL" << endl;
                // this->value = NULL;
            }
            else {
                this->value = this->next->value;
                // this->next->value = NULL;
                list *temp = this->next;
                this->next = temp->next;
                delete temp;
            }
        }
        else if(i == 1) {
            // this->next->value = NULL;
            list *temp = this->next;
            this->next = temp->next;
            delete temp;
        }
        else if(this->next == NULL) {
            cout << "object does not exits" << endl;
        }
        else
            this->next->del(i-1);
    }
    
    int length(){
        if(this->next == NULL) {
            return 1;
        }
        else 
            return this->next->length() + 1;
    }
    // ehniihees busad elementiig ustgana
    void clear(){
        if(this->next != NULL) {
            this->next->clear();
            delete this->next;
            // dood 2 mur hereg bnu?
            this->next == NULL;
            this->value == NULL;
        }
    }

    void print(){
        cout << this->value << endl;
        if(this->next != NULL)
            this->next->print();
    }
    
};