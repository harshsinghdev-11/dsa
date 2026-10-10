#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    void makeSound(){
        cout<<"Animal sound"<<endl;
    }
};

class Dog: public Animal{
    public:
    void makeSound(){
        cout<<"Dog soung"<<endl;
    }
};

class Birds{
    public:
    virtual void sound(){
        cout<<"quak quak!"<<endl;
    }
};

class Peacock:public Birds{
    public:
    void sound(){
        cout<<"mayurr"<<endl;
    }
};

// Without virtual: the base function runs, even if the object is from a child class.
// With virtual: the child's version runs, like you expect.

int main(){
    // without virtual function
    Animal* animal;
    Dog husky;
    animal = &husky;
    (*animal).makeSound(); // equivalent to animal->makeSound()
    // create the animal sound

    Birds* bird;
    Peacock peacock;
    bird = &peacock;
    bird->sound();
}