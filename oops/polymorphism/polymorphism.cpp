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

int main(){
    Animal generalAnimal;
    generalAnimal.makeSound();
    Dog husky;
    husky.makeSound();
}