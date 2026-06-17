// stack implementation using linked list

#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int num){
        val=num;
        next=NULL; 
    }
};

class Mystack{
    Node* top;
    public:
    
    Mystack(){
        top==NULL;
    };

    //push
    void push(int val){
        Node* temp = new Node(val);
        temp->next = top;
        top=temp;
    }

    //pop
    int pop(){
        if(top==NULL){
            cout<<"stack underflow";
            return -1;
        }
        Node* temp = top;
        top=top->next;
        int data = temp->val;
        delete temp;
        return data;
    };

    int peek(){
        if(top==NULL){
            cout<<"stack is empty";
            return -1;
        }
        int data = top->val;
        return data;
    }
};