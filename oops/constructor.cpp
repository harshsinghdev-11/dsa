#include<bits/stdc++.h>
using namespace std;

//can also declare the constructor outside the class

class MyClass{
    public:
    int a;
    MyClass(){
        cout<<"Constructor call";
    }
    int b;
    void mymethod();
};

class MyClass2{
    public:
    int a;
    MyClass2(int x){
        this->a = x;
    }

};

void MyClass::mymethod(){
    cout<<"hello";
}

int main(){
    MyClass myclass;
    myclass.a = 5;
    cout<<myclass.a;

    MyClass obj2;
    obj2.a = 10;
    cout<<" "<<obj2.a;
    obj2.mymethod();
    cout<<endl;

    MyClass2 obj3(55);
    cout<<obj3.a;

}